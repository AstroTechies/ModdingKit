#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "GateObjectSystem.generated.h"

class AActor;

UCLASS(Blueprintable)
class ASTRO_API UGateObjectSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
    UGateObjectSystem();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static bool BP_TryActivateGateObject(AActor* gateObjectActor);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void BP_SetGateObjectCanBeActivated(AActor* gateObjectActor, bool bCanBeActivated);
    
};

