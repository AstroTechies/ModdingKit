#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerDirectionalConnectionComponent.h"
#include "StreamingPowerDirectionalConnectionComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerDirectionalConnectionComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerDirectionalConnectionComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerDirectionalConnectionComponent GetStreamingPowerConnectionComponent(FAstroDatumRef StreamingPowerConnectionComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerDirectionalConnectionComponent FindStreamingPowerConnectionComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

