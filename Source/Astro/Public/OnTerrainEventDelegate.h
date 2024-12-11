#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "OnTerrainEventDelegate.generated.h"

class AActor;
class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTerrainEvent, TSubclassOf<UItemType>, TerrainType, const FLinearColor&, Color, FVector, Location, AActor*, Deformer);

