#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PlantDropData.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FPlantDropData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DropChance;
    
    ASTRO_API FPlantDropData();
};

