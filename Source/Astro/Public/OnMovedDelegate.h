#pragma once
#include "CoreMinimal.h"
#include "OnMovedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoved, bool, FromTool);

