#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemDropInWorldTerrainDelegateDelegate.generated.h"

class UPrimitiveComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FItemDropInWorldTerrainDelegate, UPrimitiveComponent*, Component, const FVector&, Point, const FVector&, Normal, bool, bIsTerrainComponent);

