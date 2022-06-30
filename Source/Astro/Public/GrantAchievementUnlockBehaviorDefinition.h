#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "GrantAchievementUnlockBehaviorDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UGrantAchievementUnlockBehaviorDefinition : public UAstroEntityComponentSubobjectDefinition
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    EAstroAchievementKeys Achievement;

    UGrantAchievementUnlockBehaviorDefinition();
};
