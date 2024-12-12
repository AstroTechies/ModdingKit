#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "LockingMechanismDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API ULockingMechanismDefinition : public UAstroEntityComponentSubobjectDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCanBeClosedAfterOpening: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoClosesAfterOpening: 1;
    
    ULockingMechanismDefinition();

};

