#pragma once
#include "CoreMinimal.h"
#include "EMegastructureAppendageType.generated.h"

UENUM(BlueprintType)
enum EMegastructureAppendageType {
    MegaStructure,
    Toggle,
    StaticMesh,
    SkeletalMesh,
    Actor,
    PhysicalItem,
};

