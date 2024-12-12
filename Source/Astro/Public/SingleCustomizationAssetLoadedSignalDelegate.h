#pragma once
#include "CoreMinimal.h"
#include "ECharacterCustomizationType.h"
#include "SingleCustomizationAssetLoadedSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSingleCustomizationAssetLoadedSignal, ECharacterCustomizationType, customizationType, int32, Index);

