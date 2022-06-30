#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HoverConstraint.generated.h"

class AActor;

USTRUCT()
struct FHoverConstraint {
    GENERATED_BODY()
public:
    UPROPERTY()
    FVector LocalOffset;
    
    UPROPERTY()
    AActor* Target;
    
    ASTRO_API FHoverConstraint();
};

