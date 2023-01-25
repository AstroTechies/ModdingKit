#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchProgressionComponent.h"
#include "ResearchProgressionComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UResearchProgressionComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UResearchProgressionComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchProgressionComponent GetResearchProgressionComponent(FAstroDatumRef ResearchProgressionComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchProgressionComponent FindResearchProgressionComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

