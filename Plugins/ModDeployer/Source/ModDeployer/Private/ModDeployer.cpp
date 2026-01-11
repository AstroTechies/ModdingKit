#include "ModDeployer.h"
#include "ModDeployerStyle.h"
#include "ModDeployerCommands.h"
#include "ModDeployerTask.h"
#include "ModDeployerSaveGame.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Kismet/GameplayStatics.h"
#include "LevelEditor.h"

static const FName ModDeployerTabName("ModDeployer");

#define LOCTEXT_NAMESPACE "FModDeployerModule"

void FModDeployerModule::StartupModule()
{	
	FModDeployerStyle::Initialize();
	FModDeployerStyle::ReloadTextures();

	FModDeployerCommands::Register();
	
	const FLevelEditorModule& LevelEditor = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedRef<FUICommandList> LevelEditorCommands = LevelEditor.GetGlobalLevelEditorActions();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FModDeployerCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FModDeployerModule::PluginButtonClicked),
		FCanExecuteAction());
	PluginCommands->MapAction(
		FModDeployerCommands::Get().PluginActionQuick,
		FExecuteAction::CreateRaw(this, &FModDeployerModule::PluginButtonClickedQuick),
		FCanExecuteAction());
	LevelEditorCommands->MapAction(
		FModDeployerCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FModDeployerModule::PluginButtonClicked),
		FCanExecuteAction());
	LevelEditorCommands->MapAction(
		FModDeployerCommands::Get().PluginActionQuick,
		FExecuteAction::CreateRaw(this, &FModDeployerModule::PluginButtonClickedQuick),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FModDeployerModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(ModDeployerTabName, FOnSpawnTab::CreateRaw(this, &FModDeployerModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("ModDeployerTabName", "Mod Deployer"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FModDeployerModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FModDeployerStyle::Shutdown();

	FModDeployerCommands::Unregister();
}

FReply FModDeployerModule::RunEverything()
{
	this->SaveDescriptorDataWithParam(false, true); // also save LastOpened
	(new FAsyncTask<FModDeployerTask>(EModDeployerTaskType::RunAll, this))->StartBackgroundTask();
	return FReply::Handled();
}
FReply FModDeployerModule::RunCook()
{
	this->SaveDescriptorDataWithParam(false, true); // also save LastOpened
	(new FAsyncTask<FModDeployerTask>(EModDeployerTaskType::RunCook, this))->StartBackgroundTask();
	return FReply::Handled();
}
FReply FModDeployerModule::RunPackage()
{
	this->SaveDescriptorDataWithParam(false, true); // also save LastOpened
	(new FAsyncTask<FModDeployerTask>(EModDeployerTaskType::RunPackage, this))->StartBackgroundTask();
	return FReply::Handled();
}
FReply FModDeployerModule::RunIntegrate()
{
	this->SaveDescriptorDataWithParam(false, true); // also save LastOpened
	(new FAsyncTask<FModDeployerTask>(EModDeployerTaskType::RunIntegrate, this))->StartBackgroundTask();
	return FReply::Handled();
}
FReply FModDeployerModule::RunLaunch()
{
	this->SaveDescriptorDataWithParam(false, true); // also save LastOpened
	(new FAsyncTask<FModDeployerTask>(EModDeployerTaskType::RunLaunch, this))->StartBackgroundTask();
	return FReply::Handled();
}

FReply FModDeployerModule::RunHelp()
{
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Welcome to the Mod Deployer plugin by atenfyr. This plugin is bundled with the AstroTechies ModdingKit for developing Astroneer mods.\n\nThis plugin is designed to assist in rapid mod iteration by providing a quick way to cook, package, integrate, and launch Astroneer mods for debugging purposes.\n\nTo set-up this plugin, fill out the fields in the top of the window as needed, including: your mod ID, version, the folder in which your mod assets are located, other deployment paths, and the full contents of your metadata.json file. You may hover over the name of any field to obtain more information about it. You may save these fields and load them again later using the Save config and Load config buttons, but they will also be saved automatically when closing the tab or executing a task. These saves are saved to disk and persist with editor and system restarts.\n\nTo execute the plugin, press the \"Run everything\" button. You may also execute specific tasks individually by pressing the other buttons, if desired.\n\nYou may return to this menu at any time by choosing \"Mod Deployer\" under the \"Window\" tab. You may also quickly execute the \"Run everything\" task with or without this menu open by choosing the \"Quick Deploy\" option, also under the \"Window\" tab, or by pressing the F5 key (by default). Your settings persist even with the menu closed.\n\nCopyright © 2025 atenfyr. See https://github.com/AstroTechies/ModdingKit/tree/master/Plugins/ModDeployer for more information.")));
	return FReply::Handled();
}

FText FModDeployerModule::GetText() const
{
	return FText::FromString(LogText);
}

bool FModDeployerModule::SaveDescriptorDataWithParam(bool log, bool saveLastOpened = false)
{
	bool success = false;
	if (UModDeployerSaveGame* SaveGameInstance = Cast<UModDeployerSaveGame>(UGameplayStatics::CreateSaveGameObject(UModDeployerSaveGame::StaticClass())))
	{
		SaveGameInstance->ModID = this->DescriptorData->ModID;
		SaveGameInstance->ModVersion = this->DescriptorData->ModVersion;
		SaveGameInstance->ModFolder = this->DescriptorData->ModFolder;
		SaveGameInstance->PaksFolder = this->DescriptorData->PaksFolder;
		SaveGameInstance->InstallationPaksFolder = this->DescriptorData->InstallationPaksFolder;
		SaveGameInstance->Platform = this->DescriptorData->Platform;
		SaveGameInstance->metadata = this->DescriptorData->metadata;
		success = UGameplayStatics::SaveGameToSlot(SaveGameInstance, L"ModDeployer_" + (saveLastOpened ? L"LastOpened" : this->DescriptorData->ModID), 0);
	}

	if (log) LogText = success ? "Successfully saved config" : "Failed to save config";
	return success;
}

bool FModDeployerModule::LoadDescriptorDataWithParam(bool log, bool openLastOpened = false)
{
	bool success = false;
	if (UModDeployerSaveGame* SaveGameInstance = Cast<UModDeployerSaveGame>(UGameplayStatics::LoadGameFromSlot(L"ModDeployer_" + (openLastOpened ? L"LastOpened" : this->DescriptorData->ModID), 0)))
	{
		this->DescriptorData->ModID = SaveGameInstance->ModID;
		this->DescriptorData->ModVersion = SaveGameInstance->ModVersion;
		this->DescriptorData->ModFolder = SaveGameInstance->ModFolder;
		this->DescriptorData->PaksFolder = SaveGameInstance->PaksFolder;
		this->DescriptorData->InstallationPaksFolder = SaveGameInstance->InstallationPaksFolder;
		this->DescriptorData->Platform = SaveGameInstance->Platform;
		this->DescriptorData->metadata = SaveGameInstance->metadata;
		success = true;
	}

	if (log) LogText = success ? "Successfully loaded config" : "Failed to loaded config";
	if (success && !openLastOpened) SaveDescriptorDataWithParam(false, true); // if loading a save, also overwrite the LastOpened with it
	return success;
}

FReply FModDeployerModule::SaveDescriptorDataSlate()
{
	this->SaveDescriptorDataWithParam(true, false);
	return FReply::Handled();
}

void FModDeployerModule::SaveDescriptorDataSlateLastOpened(TSharedRef<SDockTab> ClosedTab)
{
	this->SaveDescriptorDataWithParam(false, true);
}

FReply FModDeployerModule::LoadDescriptorDataSlate()
{
	this->LoadDescriptorDataWithParam(true, false);
	return FReply::Handled();
}

// blocking, don't call on the game thread!!!
FString FModDeployerModule::ExecuteIntegrator(FString parms)
{
	FString targetPathFolder = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("integrator")));
	FString targetPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(targetPathFolder, TEXT("ModIntegrator.exe")));

	try
	{
		void* PipeRead = nullptr;
		void* PipeWrite = nullptr;
		FPlatformProcess::CreatePipe(PipeRead, PipeWrite);

		FProcHandle handl = FPlatformProcess::CreateProc
		(
			*targetPath,
			*parms,
			false,
			true,
			true,
			nullptr,
			0,
			*targetPathFolder, // needed to load repak_bind correctly
			PipeWrite,
			PipeRead
		);
		if (handl.IsValid())
		{
			FString output;
			while (FPlatformProcess::IsProcRunning(handl))
			{
				output += FPlatformProcess::ReadPipe(PipeRead);
				FPlatformProcess::Sleep(0.01f);
			}
			output += FPlatformProcess::ReadPipe(PipeRead);

			FPlatformProcess::ClosePipe(PipeRead, PipeWrite);
			FPlatformProcess::WaitForProc(handl);
			FPlatformProcess::CloseProc(handl);

			return output.TrimEnd();
		}
	}
	catch (const std::runtime_error& err)
	{
		return UTF8_TO_TCHAR(err.what());
	}
	catch (...)
	{
		return TEXT("");
	}

	return TEXT("");
}

void FModDeployerModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(ModDeployerTabName);
}
void FModDeployerModule::PluginButtonClickedQuick()
{
	if (this->DescriptorData == nullptr)
	{
		this->DescriptorData = NewObject<UModDeployerDescriptorData>();
		this->LoadDescriptorDataWithParam(false, true);
	}
	(new FAsyncTask<FModDeployerTask>(EModDeployerTaskType::RunAll, this))->StartBackgroundTask();
}

TSharedRef<SDockTab> FModDeployerModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	if (this->DescriptorData == nullptr)
	{
		this->DescriptorData = NewObject<UModDeployerDescriptorData>();
		this->LoadDescriptorDataWithParam(false, true);
	}

	FPropertyEditorModule& EditModule = FModuleManager::Get().GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	{
		DetailsViewArgs.bAllowSearch = false;
		DetailsViewArgs.bShowOptions = false;
		DetailsViewArgs.bAllowMultipleTopLevelObjects = false;
		DetailsViewArgs.bAllowFavoriteSystem = false;
		DetailsViewArgs.bShowActorLabel = false;
		DetailsViewArgs.bHideSelectionTip = true;
		DetailsViewArgs.bShowScrollBar = false;
	}
	TSharedPtr<IDetailsView> DescriptorDetailView = EditModule.CreateDetailView(DetailsViewArgs);

	TSharedRef<SScrollBox> MainContent = SNew(SScrollBox);

	if (DescriptorDetailView.IsValid())
	{
		DescriptorDetailView->SetObject(this->DescriptorData);

		MainContent->AddSlot()
			//.AutoHeight()
			.Padding(1)
			[
				DescriptorDetailView.ToSharedRef()
			];
	}

	MainContent->AddSlot()
		//.AutoHeight()
		.Padding(1)
		[
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Run everything")))
						.OnClicked_Raw(this, &FModDeployerModule::RunEverything)
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Cook")))
						.OnClicked_Raw(this, &FModDeployerModule::RunCook)

				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Package")))
						.OnClicked_Raw(this, &FModDeployerModule::RunPackage)
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Integrate")))
						.OnClicked_Raw(this, &FModDeployerModule::RunIntegrate)
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Launch")))
						.OnClicked_Raw(this, &FModDeployerModule::RunLaunch)
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Save config to mod ID")))
						.OnClicked_Raw(this, &FModDeployerModule::SaveDescriptorDataSlate)
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Load config from mod ID")))
						.OnClicked_Raw(this, &FModDeployerModule::LoadDescriptorDataSlate)
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				[
					SNew(SButton).Text(FText::FromString(TEXT("Help")))
						.OnClicked_Raw(this, &FModDeployerModule::RunHelp)
				]
		];

	MainContent->AddSlot()
		//.AutoHeight()
		.Padding(1)
		[
			SNew(STextBlock)
				.Font(FSlateFontInfo(FCoreStyle::GetDefaultFont(), 12))
				.AutoWrapText(true)
				.Text_Raw(this, &FModDeployerModule::GetText)
		];

	return SNew(SDockTab)
		.OnTabClosed_Raw(this, &FModDeployerModule::SaveDescriptorDataSlateLastOpened)
		.TabRole(ETabRole::NomadTab)
		[
			MainContent
		];
}

void FModDeployerModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FModDeployerCommands::Get().PluginAction, PluginCommands);
			Section.AddMenuEntryWithCommandList(FModDeployerCommands::Get().PluginActionQuick, PluginCommands);
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FModDeployerModule, ModDeployer)
