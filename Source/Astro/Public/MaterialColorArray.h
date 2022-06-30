#pragma once
#include "CoreMinimal.h"
#include "MaterialColorArray.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FMaterialColorArray {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TArray<UMaterialInstanceDynamic*> Mats;
    
    ASTRO_API FMaterialColorArray();
};

