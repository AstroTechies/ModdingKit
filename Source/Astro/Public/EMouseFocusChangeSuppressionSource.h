#pragma once
#include "CoreMinimal.h"
#include "EMouseFocusChangeSuppressionSource.generated.h"

UENUM(BlueprintType)
enum class EMouseFocusChangeSuppressionSource : uint8 {
    PopoutIsActive,
    NavigationCommandWasIssued,
    ScrollbarActive,
    AstropediaSlidesOpen,
};

