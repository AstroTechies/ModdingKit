#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralActorRepState.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FProceduralActorRepState {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(SaveGame)
    FLinearColor TintColor;
    
    UPROPERTY(SaveGame)
    float CullingDistance;
    
    UPROPERTY(SaveGame)
    uint8 bIsBuried: 1;
    
    ASTRO_API FProceduralActorRepState();
};

