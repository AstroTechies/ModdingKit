#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchComponent.h"
#include "AstroDatumRef.h"
#include "ResearchComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UResearchComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UResearchComponentContainer();
    UFUNCTION(BlueprintPure)
    static FResearchComponent GetResearchComponent(FAstroDatumRef ResearchComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintPure)
    static FResearchComponent FindResearchComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

