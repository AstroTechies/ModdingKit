#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerMergedConnectionComponent.h"
#include "StreamingPowerMergedConnectionComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerMergedConnectionComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerMergedConnectionComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerMergedConnectionComponent GetStreamingPowerMergedConnectionComponent(FAstroDatumRef StreamingPowerMergedConnectionComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerMergedConnectionComponent FindStreamingPowerMergedConnectionComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

