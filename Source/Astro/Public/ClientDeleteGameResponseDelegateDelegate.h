#pragma once
#include "CoreMinimal.h"
#include "ClientDeleteGameResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClientDeleteGameResponseDelegate, bool, success, const FString&, saveName);

