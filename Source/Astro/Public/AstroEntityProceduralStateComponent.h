#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroEntityComponent.h"
#include "UObject/NoExportTypes.h"
#include "AstroEntityProceduralStateComponent.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroEntityProceduralStateComponent : public FAstroEntityComponent {
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
    
    UPROPERTY(SaveGame)
    uint64 ProceduralPlacementSaveID;
    
    ASTRO_API FAstroEntityProceduralStateComponent();
};

