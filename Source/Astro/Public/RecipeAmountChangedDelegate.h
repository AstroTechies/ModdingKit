#pragma once
#include "CoreMinimal.h"
#include "RecipeAmountChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecipeAmountChanged, float, Amount);

