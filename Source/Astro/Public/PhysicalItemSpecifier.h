#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItemSpecifier.generated.h"

class APhysicalItem;

USTRUCT(BlueprintType)
struct FPhysicalItemSpecifier {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<APhysicalItem> Actor;
    
    UPROPERTY(EditAnywhere)
    float Weight;
    
    ASTRO_API FPhysicalItemSpecifier();
};

