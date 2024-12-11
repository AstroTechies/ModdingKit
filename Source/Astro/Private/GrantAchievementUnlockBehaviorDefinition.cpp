#include "GrantAchievementUnlockBehaviorDefinition.h"
#include "GrantAchievementUnlockBehavior.h"

UGrantAchievementUnlockBehaviorDefinition::UGrantAchievementUnlockBehaviorDefinition() {
    this->Name = TEXT("Default__GrantAchievementUnlockBehaviorDefinition");
    this->RuntimeSubobjectType = UGrantAchievementUnlockBehavior::StaticClass();
    this->Achievement = EAstroAchievementKeys::TutorialDone;
}


