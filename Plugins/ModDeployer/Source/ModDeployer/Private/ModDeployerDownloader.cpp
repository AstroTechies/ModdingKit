#include "ModDeployerDownloader.h"
#include "ModDeployer.h"
#include "Json.h"
#include <fstream>
#include <regex>
#include <filesystem>
#include <stdexcept>

FModDeployerDownloader::FModDeployerDownloader(FModDeployerModule* parent, FString currentIntegratorVersion)
{
	ParentModule = parent;
	CurrentIntegratorVersion = currentIntegratorVersion;
}

void FModDeployerDownloader::Download()
{
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindRaw(this, &FModDeployerDownloader::RequestComplete);
	Request->SetURL("https://api.github.com/repos/atenfyr/AstroModLoader-Classic/releases");
	Request->SetVerb(TEXT("GET"));
	Request->ProcessRequest();
}

void FModDeployerDownloader::RequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	try
	{
		HttpRequest->OnProcessRequestComplete().Unbind();

		bool targetUrlFound = 0;
		FString targetUrl;
		if (HttpResponse.IsValid())
		{
			FString outputText = HttpResponse->GetContentAsString();

			//ParentModule->LogText += L"text: " + outputText.Left(10) + L"\n";

			TSharedPtr<FJsonValue> jsonParsed;
			TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(outputText);
			if (FJsonSerializer::Deserialize(jsonReader, jsonParsed))
			{
				//ParentModule->LogText += L"num entries: " + FString::FromInt(jsonParsed->AsArray().Num()) + L"\n";
				if (jsonParsed->AsArray().Num() > 0)
				{
					const TSharedPtr<FJsonObject>* valueAsObject;
					if (jsonParsed->AsArray()[0]->TryGetObject(valueAsObject))
					{
						//ParentModule->LogText += L"obj1 num keys: " + FString::FromInt(valueAsObject->Get()->Values.Num()) + L"\n";

						const TArray<TSharedPtr<FJsonValue>>* assetsArray;
						if (valueAsObject->Get()->TryGetArrayField(TEXT("assets"), assetsArray))
						{
							//ParentModule->LogText += L"assetsArray num values: " + FString::FromInt(assetsArray->Num()) + L"\n";

							for (int i = 0; i < assetsArray->Num(); i++)
							{
								const TSharedPtr<FJsonObject>* valueAsObject2;
								FString outStr;
								if ((*assetsArray)[i]->TryGetObject(valueAsObject2) && valueAsObject2->Get()->TryGetStringField(L"name", outStr) && outStr.Equals("ModIntegrator-win-x64.exe", ESearchCase::IgnoreCase))
								{
									targetUrlFound = valueAsObject2->Get()->TryGetStringField(L"browser_download_url", targetUrl);
								}
							}
						}
					}
				}
			}
		}

		if (targetUrlFound)
		{
			ParentModule->LogText += TEXT("Found integrator URL: ") + targetUrl + TEXT("\n");

			// get latest version of integrator based on url
			FString latestIntegratorVersion;

			std::regex rgx("v(\\d+\\.\\d+\\.\\d+\\.\\d+)");
			std::smatch match;
			std::string targetUrlStd = TCHAR_TO_UTF8(*targetUrl);

			if (std::regex_search(targetUrlStd, match, rgx))
			{
				latestIntegratorVersion = UTF8_TO_TCHAR(match[1].str().c_str());
				ParentModule->LogText += TEXT("Current integrator version: " + CurrentIntegratorVersion + "\n");
				ParentModule->LogText += TEXT("Latest integrator version: " + latestIntegratorVersion + "\n");
				if (!CurrentIntegratorVersion.IsEmpty() && latestIntegratorVersion == CurrentIntegratorVersion)
				{
					ParentModule->LogText += TEXT("Integrator is up-to-date\n");
					SyncEvent->Trigger();
					return;
				}
				else
				{
					ParentModule->LogText += TEXT("Integrator is not up-to-date\n");
				}
			}
			else
			{
				ParentModule->LogText += TEXT("Failed to determine latest integrator version from integrator URL\n");
				SyncEvent->Trigger();
				return;
			}

			TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
			Request->OnProcessRequestComplete().BindRaw(this, &FModDeployerDownloader::RequestComplete2);
			Request->SetURL(targetUrl);
			Request->SetVerb(TEXT("GET"));
			Request->ProcessRequest();
			return;
		}
		else
		{
			ParentModule->LogText += TEXT("Failed to find integrator URL for an unknown reason\n");
			SyncEvent->Trigger();
		}
	}
	catch (const std::runtime_error& err)
	{
		FString errMsg = UTF8_TO_TCHAR(err.what());
		ParentModule->LogText += TEXT("Failed to download integrator URL:\n") + errMsg + TEXT("\n");
		SyncEvent->Trigger();
	}
	catch (...)
	{
		ParentModule->LogText += TEXT("Failed to find integrator URL for an unknown reason\n");
		SyncEvent->Trigger();
	}
}

void FModDeployerDownloader::RequestComplete2(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	HttpRequest->OnProcessRequestComplete().Unbind();

	try
	{
		if (HttpResponse.IsValid())
		{
			TArray<uint8> outputBytes = HttpResponse->GetContent();

			FString targetPathFolder = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("ModDeployer"), TEXT("integrator")));
			FString targetPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(targetPathFolder, TEXT("ModIntegrator.exe")));

			// just in case
			std::filesystem::create_directories(TCHAR_TO_UTF8(*targetPathFolder));

			// save file to disk
			std::ofstream fs(TCHAR_TO_UTF8(*targetPath), std::ios::out | std::ios::binary);
			fs.write(reinterpret_cast<char*>(outputBytes.GetData()), outputBytes.Num());
			fs.close();

			ParentModule->LogText += TEXT("Saved integrator .exe file to \"") + targetPath + TEXT("\"\n");
		}
		else
		{
			ParentModule->LogText += TEXT("Failed to download integrator .exe file: HTTP response was invalid\n");
		}
	}
	catch (const std::runtime_error& err)
	{
		FString errMsg = UTF8_TO_TCHAR(err.what());
		ParentModule->LogText += TEXT("Failed to download integrator .exe file:\n") + errMsg + TEXT("\n");
	}
	catch (...)
	{
		ParentModule->LogText += TEXT("Failed to download integrator .exe file for an unknown reason\n");
	}

	SyncEvent->Trigger();
}
