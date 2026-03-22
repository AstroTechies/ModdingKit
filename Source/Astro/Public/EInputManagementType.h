#pragma once
#include "CoreMinimal.h"
#include "EInputManagementType.generated.h"

UENUM(BlueprintType)
enum class EInputManagementType : uint8 {
    None,
    SelectedRecipe,
    AnyRecipe,
};

