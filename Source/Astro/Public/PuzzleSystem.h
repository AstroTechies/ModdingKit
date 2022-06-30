#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "PuzzleSystem.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPuzzleSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
    UPuzzleSystem();
};
