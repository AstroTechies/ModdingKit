#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerDirectionalConnectionComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerDirectionalConnectionComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UStreamingPowerDirectionalConnectionComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UStreamingPowerDirectionalConnectionComponentContainer();
    UFUNCTION(BlueprintPure)
    static FStreamingPowerDirectionalConnectionComponent GetStreamingPowerConnectionComponent(FAstroDatumRef StreamingPowerConnectionComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FStreamingPowerDirectionalConnectionComponent FindStreamingPowerConnectionComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
