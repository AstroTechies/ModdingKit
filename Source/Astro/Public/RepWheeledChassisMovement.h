#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RepLinkedChassisMovement.h"
#include "RepWheeledChassisMovement.generated.h"

USTRUCT(BlueprintType)
struct FRepWheeledChassisMovement {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRepMovement Movement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRepLinkedChassisMovement> linkedMovement;
    
    ASTRO_API FRepWheeledChassisMovement();
};

