#pragma once
#include "CoreMinimal.h"
#include "EStatusModifierType.h"
#include "OnStatusModifierDeactivatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatusModifierDeactivated, EStatusModifierType, statusModifierType);

