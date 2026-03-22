#pragma once
#include "CoreMinimal.h"
#include "MaterialColorArray.h"
#include "MaterialIndexArray.h"
#include "MaterialInstanceCache.generated.h"

USTRUCT(BlueprintType)
struct FMaterialInstanceCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialColorArray> CachedColorInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialIndexArray> CachedIndexInstances;
    
    ASTRO_API FMaterialInstanceCache();
};

