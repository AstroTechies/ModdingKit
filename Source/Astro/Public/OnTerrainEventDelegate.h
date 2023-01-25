#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Templates/SubclassOf.h"
#include "OnTerrainEventDelegate.generated.h"

class AActor;
class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTerrainEvent, TSubclassOf<UItemType>, TerrainType, const FLinearColor&, Color, FVector, Location, AActor*, Deformer);

