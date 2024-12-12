#pragma once
#include "CoreMinimal.h"
#include "T2MaterialArray.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FT2MaterialArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> Materials;
    
    TERRAIN2_API FT2MaterialArray();
};

