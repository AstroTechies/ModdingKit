#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RepLinkedChassisMovement.generated.h"

class UWheeledChassisComponent;

USTRUCT(BlueprintType)
struct FRepLinkedChassisMovement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWheeledChassisComponent* linkedChassis;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRepMovement Movement;
    
    ASTRO_API FRepLinkedChassisMovement();
};

