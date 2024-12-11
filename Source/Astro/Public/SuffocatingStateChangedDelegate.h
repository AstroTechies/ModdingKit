#pragma once
#include "CoreMinimal.h"
#include "SuffocatingStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSuffocatingStateChanged, bool, Suffocating);

