#pragma once
#include "CoreMinimal.h"
#include "OutroSequenceActorCreatedDelegate.generated.h"

class ALevelSequenceActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOutroSequenceActorCreated, ALevelSequenceActor*, OutroSequenceActor);

