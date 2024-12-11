#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerVampireConnectionComponent.h"
#include "StreamingPowerVampireConnectionComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerVampireConnectionComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerVampireConnectionComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerVampireConnectionComponent GetStreamingPowerVampireConnectionComponent(FAstroDatumRef StreamingPowerVampireConnectionComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerVampireConnectionComponent FindStreamingPowerVampireConnectionComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

