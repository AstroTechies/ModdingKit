#pragma once
#include "CoreMinimal.h"
#include "EViewPrimativeType.generated.h"

UENUM()
enum class EViewPrimativeType {
    PrimaryViewActor,
    SecondaryViewActor,
    TertiaryViewActor,
    TracedActor,
    TracedActorAndChildren,
};

