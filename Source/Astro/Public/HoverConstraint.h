#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HoverConstraint.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FHoverConstraint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    ASTRO_API FHoverConstraint();
};

