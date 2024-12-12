#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerNodeComponent.h"
#include "StreamingPowerNodeComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerNodeComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerNodeComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerNodeComponent GetStreamingPowerNodeComponent(FAstroDatumRef StreamingPowerNodeComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerNodeComponent FindStreamingPowerNodeComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

