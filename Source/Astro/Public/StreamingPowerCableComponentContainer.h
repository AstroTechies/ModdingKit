#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "StreamingPowerCableComponent.h"
#include "StreamingPowerCableComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerCableComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UStreamingPowerCableComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerCableComponent GetStreamingPowerCableComponent(FAstroDatumRef StreamingPowerCableComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStreamingPowerCableComponent FindStreamingPowerCableComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

