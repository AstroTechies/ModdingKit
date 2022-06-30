#pragma once
#include "CoreMinimal.h"
#include "UsingMouseChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUsingMouseChanged, bool, bUsingMouseChanged);

