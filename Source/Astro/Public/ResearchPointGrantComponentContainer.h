#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchPointGrantComponent.h"
#include "AstroDatumRef.h"
#include "ResearchPointGrantComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UResearchPointGrantComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UResearchPointGrantComponentContainer();
    UFUNCTION(BlueprintPure)
    static FResearchPointGrantComponent GetResearchPointGrantComponent(FAstroDatumRef ResearchPointGrantComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintPure)
    static FResearchPointGrantComponent FindResearchPointGrantComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

