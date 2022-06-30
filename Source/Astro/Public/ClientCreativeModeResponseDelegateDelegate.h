#pragma once
#include "CoreMinimal.h"
#include "ClientCreativeModeResponseDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FClientCreativeModeResponseDelegate, bool, success, bool, Enable);

