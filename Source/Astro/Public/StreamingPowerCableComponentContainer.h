#pragma once
#include "CoreMinimal.h"
#include "StreamingPowerCableComponent.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "StreamingPowerCableComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UStreamingPowerCableComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UStreamingPowerCableComponentContainer();
    UFUNCTION(BlueprintPure)
    static FStreamingPowerCableComponent GetStreamingPowerCableComponent(FAstroDatumRef StreamingPowerCableComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FStreamingPowerCableComponent FindStreamingPowerCableComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
