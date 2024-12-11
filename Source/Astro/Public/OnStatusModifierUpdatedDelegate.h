#pragma once
#include "CoreMinimal.h"
#include "EStatusModifierType.h"
#include "OnStatusModifierUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStatusModifierUpdated, EStatusModifierType, statusModifierType, float, newValue);

