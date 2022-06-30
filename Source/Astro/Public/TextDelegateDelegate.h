#pragma once
#include "CoreMinimal.h"
#include "TextDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTextDelegate, const FText&, Text);

