#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RepLinkedChassisMovement.generated.h"

class UWheeledChassisComponent;

USTRUCT(BlueprintType)
struct FRepLinkedChassisMovement {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UWheeledChassisComponent* linkedChassis;
    
    UPROPERTY()
    FRepMovement Movement;
    
    ASTRO_API FRepLinkedChassisMovement();
};

