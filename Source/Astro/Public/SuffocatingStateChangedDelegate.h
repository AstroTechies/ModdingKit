#pragma once
#include "CoreMinimal.h"
#include "SuffocatingStateChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSuffocatingStateChanged, bool, Suffocating);

