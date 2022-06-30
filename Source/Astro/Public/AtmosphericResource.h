#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AtmosphericResource.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAtmosphericResource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ResourceItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Density;
    
    ASTRO_API FAtmosphericResource();
};

