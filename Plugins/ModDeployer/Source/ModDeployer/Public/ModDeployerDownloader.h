#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

class FModDeployerModule;

class FModDeployerDownloader
{

public:
	FModDeployerDownloader(FModDeployerModule* parent, FString currentIntegratorVersion);

	UPROPERTY()
	FModDeployerModule* ParentModule = nullptr;
	UPROPERTY()
	FString CurrentIntegratorVersion;
	UPROPERTY()
	FEvent* SyncEvent = FPlatformProcess::CreateSynchEvent(false);

	void Download();
	void RequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	void RequestComplete2(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
};