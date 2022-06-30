#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerMergedConnectionComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerMergedConnectionComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UStreamingPowerMergedConnectionComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UStreamingPowerMergedConnectionComponentContainer();
    UFUNCTION(BlueprintPure)
    static FStreamingPowerMergedConnectionComponent GetStreamingPowerMergedConnectionComponent(FAstroDatumRef StreamingPowerMergedConnectionComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FStreamingPowerMergedConnectionComponent FindStreamingPowerMergedConnectionComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
