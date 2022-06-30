#pragma once
#include "CoreMinimal.h"
#include "ClickQueryDelegateDelegate.generated.h"

class UClickQuery;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClickQueryDelegate, UClickQuery*, ClickQuery);

