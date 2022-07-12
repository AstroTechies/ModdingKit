#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "StreamingPowerVampireConnectionComponent.h"
#include "StreamingPowerVampireConnectionComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerVampireConnectionComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerVampireConnectionComponentContainer();
    UFUNCTION(BlueprintPure)
    static FStreamingPowerVampireConnectionComponent GetStreamingPowerVampireConnectionComponent(FAstroDatumRef StreamingPowerVampireConnectionComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintPure)
    static FStreamingPowerVampireConnectionComponent FindStreamingPowerVampireConnectionComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

