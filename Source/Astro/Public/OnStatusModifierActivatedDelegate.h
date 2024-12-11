#pragma once
#include "CoreMinimal.h"
#include "EStatusModifierType.h"
#include "OnStatusModifierActivatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatusModifierActivated, EStatusModifierType, statusModifierType);

