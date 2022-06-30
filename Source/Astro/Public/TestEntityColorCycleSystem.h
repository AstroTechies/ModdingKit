#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "TestEntityColorCycleSystem.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UTestEntityColorCycleSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
    UTestEntityColorCycleSystem();
};
