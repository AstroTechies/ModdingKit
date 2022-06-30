#pragma once
#include "CoreMinimal.h"
#include "MaterialColorArray.h"
#include "MaterialIndexArray.h"
#include "MaterialInstanceCache.generated.h"

USTRUCT(BlueprintType)
struct FMaterialInstanceCache {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TMap<FName, FMaterialColorArray> CachedColorInstances;
    
    UPROPERTY(Transient)
    TMap<FName, FMaterialIndexArray> CachedIndexInstances;
    
    ASTRO_API FMaterialInstanceCache();
};

