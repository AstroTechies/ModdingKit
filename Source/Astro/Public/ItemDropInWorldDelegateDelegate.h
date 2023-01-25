#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ItemDropInWorldDelegateDelegate.generated.h"

class UPrimitiveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FItemDropInWorldDelegate, UPrimitiveComponent*, Component, const FVector&, Point, const FVector&, Normal);

