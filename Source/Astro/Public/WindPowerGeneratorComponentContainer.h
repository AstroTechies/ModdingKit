#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "WindPowerGeneratorComponent.h"
#include "WindPowerGeneratorComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UWindPowerGeneratorComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UWindPowerGeneratorComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FWindPowerGeneratorComponent GetWindPowerGeneratorComponent(FAstroDatumRef WindPowerGeneratorComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FWindPowerGeneratorComponent FindWindPowerGeneratorComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

