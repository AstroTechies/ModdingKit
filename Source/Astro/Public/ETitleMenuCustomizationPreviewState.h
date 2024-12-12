#pragma once
#include "CoreMinimal.h"
#include "ETitleMenuCustomizationPreviewState.generated.h"

UENUM(BlueprintType)
enum class ETitleMenuCustomizationPreviewState : uint8 {
    None,
    TransitioningIntoPreview,
    TransitioningOutOfPreview,
    InCustomizationPreview,
    TransitioningIntoFinalization,
    TransitioningOutOfFinalization,
    FinalizingCustomization,
    Invalid,
};

