#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "GateObjectEventListener.generated.h"

class AActor;

UCLASS(Blueprintable, Blueprintable)
class UGateObjectEventListener : public UAstroEntityComponentSubobject
{
    GENERATED_BODY()
public:
    UGateObjectEventListener();
    UFUNCTION()
    void OnPlayerCharacterInProximityDestroyed(AActor *playerCharacter);
};
