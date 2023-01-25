#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ItemDropInWorldTerrainDelegateDelegate.generated.h"

class UPrimitiveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FItemDropInWorldTerrainDelegate, UPrimitiveComponent*, Component, const FVector&, Point, const FVector&, Normal, bool, bIsTerrainComponent);

