#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RepLinkedChassisMovement.h"
#include "RepWheeledChassisMovement.generated.h"

USTRUCT(BlueprintType)
struct FRepWheeledChassisMovement {
    GENERATED_BODY()
public:
    UPROPERTY()
    FRepMovement Movement;
    
    UPROPERTY()
    TArray<FRepLinkedChassisMovement> linkedMovement;
    
    ASTRO_API FRepWheeledChassisMovement();
};

