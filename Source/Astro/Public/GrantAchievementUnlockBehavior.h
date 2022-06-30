#pragma once
#include "CoreMinimal.h"
#include "UnlockBehavior.h"
#include "GrantAchievementUnlockBehavior.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UGrantAchievementUnlockBehavior : public UUnlockBehavior
{
    GENERATED_BODY()
public:
    UGrantAchievementUnlockBehavior();
};
