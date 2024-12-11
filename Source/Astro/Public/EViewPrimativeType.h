#pragma once
#include "CoreMinimal.h"
#include "EViewPrimativeType.generated.h"

UENUM(BlueprintType)
enum class EViewPrimativeType : uint8 {
    PrimaryViewActor,
    SecondaryViewActor,
    TertiaryViewActor,
    TracedActor,
    TracedActorAndChildren,
};

