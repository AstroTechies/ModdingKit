#pragma once
#include "CoreMinimal.h"
#include "ClientNewGameResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClientNewGameResponseDelegate, bool, success, const FString&, saveName);

