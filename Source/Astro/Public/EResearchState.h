#pragma once
#include "CoreMinimal.h"
#include "EResearchState.generated.h"

UENUM(BlueprintType)
enum class EResearchState : uint8 {
    WaitingForSubjects,
    InvalidSubject,
    ReadyToResearch,
    Researching,
    InsufficientPowerToContinue,
    ResearchComplete,
};

