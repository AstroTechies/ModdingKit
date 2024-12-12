#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DropInWorldDelegateDelegate.generated.h"

class UPrimitiveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDropInWorldDelegate, UPrimitiveComponent*, Component, const FVector&, Point, const FVector&, Normal);

