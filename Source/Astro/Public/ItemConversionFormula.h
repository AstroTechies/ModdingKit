#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ItemConversionFormula.generated.h"

UCLASS(Abstract, Blueprintable, Transient)
class ASTRO_API UItemConversionFormula : public UObject {
    GENERATED_BODY()
public:
    UItemConversionFormula();
};

