#pragma once
#include "CoreMinimal.h"
#include "ECharacterCustomizationType.h"
#include "CustomizationAssetLoadedSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCustomizationAssetLoadedSignal, ECharacterCustomizationType, customizationType);

