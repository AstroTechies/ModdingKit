#pragma once
#include "CoreMinimal.h"
#include "MaterialColorArray.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FMaterialColorArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> Mats;
    
    ASTRO_API FMaterialColorArray();
};

