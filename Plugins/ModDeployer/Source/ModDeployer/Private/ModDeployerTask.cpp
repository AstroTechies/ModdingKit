#include "ModDeployerTask.h"
#include "ModDeployer.h"
#include <vector>

bool FModDeployerTask::RunCook_Inner()
{
	ParentModDeployer->LogText += "\nCooking\n";
	if (ParentModDeployer->DescriptorData == nullptr) return false;
	FString exePath = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::EngineDir(), TEXT("Binaries"), TEXT("Win64"), TEXT("UE4Editor-Cmd.exe")));
	FString params = TEXT("\"") + FPaths::ConvertRelativePathToFull(FPaths::GetProjectFilePath()) + TEXT("\" -run=cook -targetplatform=WindowsNoEditor -CrashForUAT -unattended");

	ParentModDeployer->LogText += (exePath + " " + params + "\n");

	FProcHandle handl = FPlatformProcess::CreateProc
	(
		*exePath,
		*params,
		false,
		false,
		false,
		nullptr,
		0,
		nullptr,
		nullptr
	);
	FPlatformProcess::WaitForProc(handl);

	ParentModDeployer->LogText += TEXT("All done\n");
	return true;
}
bool FModDeployerTask::RunPackage_Inner()
{
	ParentModDeployer->LogText += TEXT("\nPackaging\n");

	// copy folder to staging in Intermediate
	FString modFolder = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("Intermediate"), TEXT("TempMod")));
	FString sourceFolder = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Cooked"), TEXT("WindowsNoEditor"), ParentModDeployer->DescriptorData->ModFolder));
	FString targetFolder = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("Intermediate"), TEXT("TempMod"), ParentModDeployer->DescriptorData->ModFolder));
	FString staticAssetsFolder = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("ModStaticAssets"), ParentModDeployer->DescriptorData->ModID));
	FString targetMetadataFilePath = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("Intermediate"), TEXT("TempMod"), TEXT("metadata.json")));

	// we use std here to copy files
	try
	{
		std::filesystem::remove_all(TCHAR_TO_UTF8(*modFolder));
		std::filesystem::create_directories(TCHAR_TO_UTF8(*targetFolder));
		std::filesystem::create_directories(TCHAR_TO_UTF8(*staticAssetsFolder));
		std::filesystem::copy(TCHAR_TO_UTF8(*sourceFolder), TCHAR_TO_UTF8(*targetFolder), std::filesystem::copy_options::overwrite_existing | std::filesystem::copy_options::recursive);
		
		// we want static assets to override our assets, so we copy it after
		std::filesystem::copy(TCHAR_TO_UTF8(*staticAssetsFolder), TCHAR_TO_UTF8(*modFolder), std::filesystem::copy_options::overwrite_existing | std::filesystem::copy_options::recursive);

		std::string outText = TCHAR_TO_UTF8(*(ParentModDeployer->DescriptorData->metadata));
		std::ofstream out(TCHAR_TO_UTF8(*targetMetadataFilePath), std::ios_base::out);
		out.write(outText.c_str(), outText.length());
		out.close();
	}
	catch (const std::runtime_error& err)
	{
		FString errMsg = UTF8_TO_TCHAR(err.what());
		ParentModDeployer->LogText += TEXT("Failed copying files:\n") + errMsg + TEXT("\n");
		return false;
	}
	catch (...)
	{
		ParentModDeployer->LogText += TEXT("Failed copying files for an unknown reason\n");
		return false;
	}

	// package using repak
	// 9xx prefixes are reserved for external applications. we define 989 as being for "ModDeployer temporary mods"
	FString localappdataConstStr(TEXT("%LOCALAPPDATA%"));
	FString localappdata(getenv("LOCALAPPDATA"));
	FString pakFileName = TEXT("989-") + (ParentModDeployer->DescriptorData->ModID) + "-" + (ParentModDeployer->DescriptorData->ModVersion) + TEXT("_P.pak");
	FString paksFolder = FPaths::ConvertRelativePathToFull((ParentModDeployer->DescriptorData->PaksFolder).Replace(*localappdataConstStr, *localappdata, ESearchCase::IgnoreCase));
	FString finalPakPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(paksFolder, pakFileName));

	// delete all 989- files before packaging
	try
	{
		std::vector<std::filesystem::path> pathsToDelete;
		for (const auto& entry : std::filesystem::directory_iterator(TCHAR_TO_UTF8(*paksFolder)))
		{
			if (entry.is_regular_file())
			{
				std::string fileName = entry.path().filename().string();
				if (fileName.rfind("989-", 0) == 0)
				{
					pathsToDelete.push_back(entry.path());
				}
			}
		}
		for (const auto& pathToDelete : pathsToDelete)
		{
			std::filesystem::remove(pathToDelete);
		}
	}
	catch (const std::runtime_error& err)
	{
		FString errMsg = UTF8_TO_TCHAR(err.what());
		ParentModDeployer->LogText += TEXT("Failed deleting old temp paks:\n") + errMsg + TEXT("\n");
		return false;
	}
	catch (...)
	{
		ParentModDeployer->LogText += TEXT("Failed deleting old temp paks for an unknown reason\n");
		return false;
	}

	// execute repak.exe
	FString repakExe = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("repak"), TEXT("repak.exe")));
	FString params = TEXT("pack --version V4 --compression Zlib \"") + modFolder + TEXT("\" \"") + finalPakPath + TEXT("\"");
	ParentModDeployer->LogText += repakExe + " " + params + "\n";

	FProcHandle handl = FPlatformProcess::CreateProc
	(
		*repakExe,
		*params,
		false,
		true,
		true,
		nullptr,
		0,
		nullptr,
		nullptr
	);
	FPlatformProcess::WaitForProc(handl);

	if (std::filesystem::exists(TCHAR_TO_UTF8(*finalPakPath)))
	{
		ParentModDeployer->LogText += TEXT("Successfully created .pak file\n");
	}
	else
	{
		ParentModDeployer->LogText += TEXT("Failed to create .pak file\n");
		return false;
	}

	ParentModDeployer->LogText += TEXT("All done\n");
	return true;
}
bool FModDeployerTask::RunIntegrate_Inner()
{
	// execute integrator
	ParentModDeployer->LogText += TEXT("\nIntegrating\n");

	FString localappdataConstStr(TEXT("%LOCALAPPDATA%"));
	FString localappdata(getenv("LOCALAPPDATA"));

	FString integratorVersion = ParentModDeployer->ExecuteIntegrator(TEXT("version"));
	if (integratorVersion.IsEmpty() || !ParentModDeployer->HaveWeCheckedForIntegratorUpdatesAlready)
	{
		ParentModDeployer->HaveWeCheckedForIntegratorUpdatesAlready = 1;
		FModDeployerDownloader downloader = FModDeployerDownloader(this->ParentModDeployer, integratorVersion);
		downloader.Download();
		downloader.SyncEvent->Wait();
	}

	FString integratorOutput = ParentModDeployer->ExecuteIntegrator((ParentModDeployer->DescriptorData->PaksFolder).Replace(*localappdataConstStr, *localappdata, ESearchCase::IgnoreCase) + TEXT(" ") + ParentModDeployer->DescriptorData->InstallationPaksFolder);
	if (integratorOutput.IsEmpty())
	{
		ParentModDeployer->LogText += TEXT("Integrator failed to execute! Aborting!");
		return false;
	}
	else
	{
		ParentModDeployer->LogText += integratorOutput + TEXT("\n");
	}

	ParentModDeployer->LogText += TEXT("All done\n");
	return true;
}
bool FModDeployerTask::RunLaunch_Inner()
{
	// launch game
	ParentModDeployer->LogText += TEXT("\nLaunching\n");

	if (ParentModDeployer->DescriptorData->Platform == EModDeployerPlatformType::Steam)
	{
		FPlatformProcess::LaunchURL(TEXT("steam://run/361420"), NULL, NULL);
	}
	else if (ParentModDeployer->DescriptorData->Platform == EModDeployerPlatformType::MicrosoftStore)
	{
		FPlatformProcess::LaunchURL(TEXT("shell:appsFolder\\SystemEraSoftworks.29415440E1269_ftk5pbg2rayv2!AppSystemEraSoftworks29415440E1269Shipping"), NULL, NULL);
	}
	else
	{
		ParentModDeployer->LogText += TEXT("Failed to launch game for unknown platform\n");
		return false;
	}

	ParentModDeployer->LogText += TEXT("All done\n");
	return true;
}
