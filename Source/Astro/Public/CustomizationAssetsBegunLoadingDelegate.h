#pragma once
#include "CoreMinimal.h"
#include "ECharacterCustomizationType.h"
#include "CustomizationAssetsBegunLoadingDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCustomizationAssetsBegunLoading, ECharacterCustomizationType, customizationType, int32, Count);

