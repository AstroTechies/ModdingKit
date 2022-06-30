#pragma once
#include "CoreMinimal.h"
#include "ClientLoadGameResponseDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClientLoadGameResponseDelegate, bool, success, const FString&, saveName);

