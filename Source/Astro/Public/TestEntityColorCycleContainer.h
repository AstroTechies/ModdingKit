#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "TestEntityColorCycleComponent.h"
#include "TestEntityColorCycleContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UTestEntityColorCycleContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UTestEntityColorCycleContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTestEntityColorCycleComponent GetTestEntityColorCycleComponent(FAstroDatumRef ColorCycleComponentRef, bool& bOutSuccess);
    
};

