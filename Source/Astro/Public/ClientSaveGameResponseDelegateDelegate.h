#pragma once
#include "CoreMinimal.h"
#include "ClientSaveGameResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClientSaveGameResponseDelegate, bool, success, const FString&, saveName);

