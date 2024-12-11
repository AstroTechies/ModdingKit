#pragma once
#include "CoreMinimal.h"
#include "IsBuriedChangedEventDelegate.generated.h"

class UTerrainPhysicsComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsBuriedChangedEvent, UTerrainPhysicsComponent*, TerrainPhysics);

