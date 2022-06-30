#pragma once
#include "CoreMinimal.h"
#include "OnSnailFedChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSnailFedChanged, bool, bIsFed);

