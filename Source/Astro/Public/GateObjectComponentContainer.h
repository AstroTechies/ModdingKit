#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "GateObjectComponent.h"
#include "AstroDatumRef.h"
#include "GateObjectComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UGateObjectComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UGateObjectComponentContainer();
    UFUNCTION(BlueprintPure)
    static FGateObjectComponent GetGateObjectComponent(FAstroDatumRef GateObjectComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintPure)
    static FGateObjectComponent FindGateObjectComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

