#pragma once
#include "CoreMinimal.h"
#include "PlayerProximityEventCallbackDelegate.generated.h"

class AAstroCharacter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerProximityEventCallback, AAstroCharacter*, CharacterInProximity);

