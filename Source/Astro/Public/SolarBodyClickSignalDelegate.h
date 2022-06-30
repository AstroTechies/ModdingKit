#pragma once
#include "CoreMinimal.h"
#include "SolarBodyClickSignalDelegate.generated.h"

class ASolarBody;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSolarBodyClickSignal, ASolarBody*, SolarBody);

