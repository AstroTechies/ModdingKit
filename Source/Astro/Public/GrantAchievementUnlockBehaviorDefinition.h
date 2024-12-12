#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "EAstroAchievementKeys.h"
#include "GrantAchievementUnlockBehaviorDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UGrantAchievementUnlockBehaviorDefinition : public UAstroEntityComponentSubobjectDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys Achievement;
    
    UGrantAchievementUnlockBehaviorDefinition();

};

