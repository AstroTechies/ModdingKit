#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "BackpackOxygenTankProperties.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FBackpackOxygenTankProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> OxygenTankChildActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OxygenTankCapacity;
    
    ASTRO_API FBackpackOxygenTankProperties();
};

