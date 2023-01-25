#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "GateObjectComponent.h"
#include "GateObjectComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UGateObjectComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UGateObjectComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGateObjectComponent GetGateObjectComponent(FAstroDatumRef GateObjectComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGateObjectComponent FindGateObjectComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

