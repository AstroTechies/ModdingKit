#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerMergedNodeComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerMergedNodeComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerMergedNodeComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerMergedNodeComponentContainer();
    UFUNCTION(BlueprintPure)
    static FStreamingPowerMergedNodeComponent GetStreamingPowerMergedNodeComponent(FAstroDatumRef StreamingPowerMergedNodeComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintPure)
    static FStreamingPowerMergedNodeComponent FindStreamingPowerMergedNodeComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

