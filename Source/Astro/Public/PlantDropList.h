#pragma once
#include "CoreMinimal.h"
#include "PlantDropData.h"
#include "PlantDropList.generated.h"

USTRUCT(BlueprintType)
struct FPlantDropList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlantDropData> PlantDropList;
    
    ASTRO_API FPlantDropList();
};

