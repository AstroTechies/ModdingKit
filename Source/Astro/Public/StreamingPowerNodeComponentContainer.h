#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerNodeComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerNodeComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UStreamingPowerNodeComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UStreamingPowerNodeComponentContainer();
    UFUNCTION(BlueprintPure)
    static FStreamingPowerNodeComponent GetStreamingPowerNodeComponent(FAstroDatumRef StreamingPowerNodeComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FStreamingPowerNodeComponent FindStreamingPowerNodeComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
