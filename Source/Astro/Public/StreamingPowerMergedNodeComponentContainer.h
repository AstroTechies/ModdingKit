#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerMergedNodeComponent.h"
#include "StreamingPowerMergedNodeComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerMergedNodeComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerMergedNodeComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerMergedNodeComponent GetStreamingPowerMergedNodeComponent(FAstroDatumRef StreamingPowerMergedNodeComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerMergedNodeComponent FindStreamingPowerMergedNodeComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

