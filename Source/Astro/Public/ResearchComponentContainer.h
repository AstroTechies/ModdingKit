#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchComponent.h"
#include "ResearchComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UResearchComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UResearchComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchComponent GetResearchComponent(FAstroDatumRef ResearchComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchComponent FindResearchComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

