#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "LockingMechanismDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API ULockingMechanismDefinition : public UAstroEntityComponentSubobjectDefinition
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bCanBeClosedAfterOpening : 1;

    UPROPERTY(EditAnywhere)
    uint8 bAutoClosesAfterOpening : 1;

    ULockingMechanismDefinition();
};
