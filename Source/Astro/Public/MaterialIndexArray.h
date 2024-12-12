#pragma once
#include "CoreMinimal.h"
#include "MaterialIndexArray.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FMaterialIndexArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> Mats;
    
    ASTRO_API FMaterialIndexArray();
};

