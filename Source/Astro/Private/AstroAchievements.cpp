#include "AstroAchievements.h"
#include "Templates/SubclassOf.h"

UAstroAchievements::UAstroAchievements() {
}

void UAstroAchievements::IncrementAchievementProgressForAllPlayers(EAstroAchievementKeys Achievement, int32 AddedProgress, UObject* WorldContextObject) {
}

void UAstroAchievements::IncrementAchievementProgress(EAstroAchievementKeys Achievement, int32 AddedProgress, APlayerController* Player) {
}

void UAstroAchievements::IncrementAchievementFloatProgressForAllPlayers(EAstroAchievementKeys Achievement, float AddedProgress, UObject* WorldContextObject) {
}

void UAstroAchievements::IncrementAchievementFloatProgress(EAstroAchievementKeys Achievement, float AddedProgress, APlayerController* Player) {
}

void UAstroAchievements::AwardAchievementForAllPlayers(EAstroAchievementKeys Achievement, UObject* WorldContextObject) {
}

void UAstroAchievements::AwardAchievement(EAstroAchievementKeys Achievement, APlayerController* Player) {
}

void UAstroAchievements::AddAchievementCollectionItemForAllPlayers(EAstroAchievementKeys Achievement, TSubclassOf<UItemType> Item, UObject* WorldContextObject) {
}

void UAstroAchievements::AddAchievementCollectionItem(EAstroAchievementKeys Achievement, TSubclassOf<UItemType> Item, APlayerController* Player) {
}


