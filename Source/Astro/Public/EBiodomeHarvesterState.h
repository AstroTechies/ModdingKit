#pragma once
#include "CoreMinimal.h"
#include "EBiodomeHarvesterState.generated.h"

UENUM(BlueprintType)
enum EBiodomeHarvesterState {
    Inactive,
    WaitingForNextSection,
    MovingToSection,
    HoveringAtSection,
    ReturningToBase,
};

