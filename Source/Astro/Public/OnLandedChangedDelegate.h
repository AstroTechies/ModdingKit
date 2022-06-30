#pragma once
#include "CoreMinimal.h"
#include "OnLandedChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLandedChanged, bool, bIsLanded);

