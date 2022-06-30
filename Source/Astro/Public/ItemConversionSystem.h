#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "ItemConversionSystem.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UItemConversionSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
    UItemConversionSystem();
};
