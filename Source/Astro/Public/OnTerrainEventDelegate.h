#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "OnTerrainEventDelegate.generated.h"

class UItemType;
class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTerrainEvent, TSubclassOf<UItemType>, TerrainType, const FLinearColor&, Color, FVector, Location, AActor*, Deformer);

