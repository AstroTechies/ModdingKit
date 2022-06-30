#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "ResearchProgressionComponent.h"
#include "AstroDatumRef.h"
#include "ResearchProgressionComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UResearchProgressionComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UResearchProgressionComponentContainer();
    UFUNCTION(BlueprintPure)
    static FResearchProgressionComponent GetResearchProgressionComponent(FAstroDatumRef ResearchProgressionComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FResearchProgressionComponent FindResearchProgressionComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
