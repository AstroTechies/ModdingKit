#pragma once
#include "CoreMinimal.h"
#include "ClientCreativeModeResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClientCreativeModeResponseDelegate, bool, success, bool, Enable);

