#pragma once
#include "CoreMinimal.h"
#include "ActorOnscreenSignalDelegate.generated.h"

class AActor;
class APlayController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FActorOnscreenSignal, AActor*, Actor, bool, bIsOnscreen, APlayController*, Player);

