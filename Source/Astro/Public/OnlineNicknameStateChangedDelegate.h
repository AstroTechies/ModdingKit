#pragma once
#include "CoreMinimal.h"
#include "OnlineNicknameStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnlineNicknameStateChanged, bool, Visible, const FString&, NickName);

