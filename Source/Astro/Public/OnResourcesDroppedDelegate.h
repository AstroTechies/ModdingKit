#pragma once
#include "CoreMinimal.h"
#include "OnResourcesDroppedDelegate.generated.h"

class APhysicalItem;
class UBiodomePlantComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResourcesDropped, UBiodomePlantComponent*, plant, TArray<APhysicalItem*>, itemsDropped);

