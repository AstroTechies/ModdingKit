#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "TestEntityColorCycleComponent.h"
#include "AstroDatumRef.h"
#include "TestEntityColorCycleContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UTestEntityColorCycleContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UTestEntityColorCycleContainer();
    UFUNCTION(BlueprintPure)
    static FTestEntityColorCycleComponent GetTestEntityColorCycleComponent(FAstroDatumRef ColorCycleComponentRef, bool &bOutSuccess);
};
