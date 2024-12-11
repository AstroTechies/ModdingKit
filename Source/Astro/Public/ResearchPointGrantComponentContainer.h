#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchPointGrantComponent.h"
#include "ResearchPointGrantComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UResearchPointGrantComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UResearchPointGrantComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchPointGrantComponent GetResearchPointGrantComponent(FAstroDatumRef ResearchPointGrantComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchPointGrantComponent FindResearchPointGrantComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

