#pragma once
#include "CoreMinimal.h"
#include "AstroDatumContainer.h"
#include "AstroEntityContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroEntityContainer : public UAstroDatumContainer
{
    GENERATED_BODY()
public:
    UAstroEntityContainer();
};
