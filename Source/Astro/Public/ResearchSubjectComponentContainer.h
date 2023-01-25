#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchSubjectComponent.h"
#include "ResearchSubjectComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UResearchSubjectComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UResearchSubjectComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchSubjectComponent GetResearchSubjectComponent(FAstroDatumRef ResearchSubjectComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FResearchSubjectComponent FindResearchSubjectComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

