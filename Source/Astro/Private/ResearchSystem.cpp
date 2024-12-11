#include "ResearchSystem.h"
#include "Templates/SubclassOf.h"

UResearchSystem::UResearchSystem() {
}

void UResearchSystem::StartOrInterruptResearch(FAstroDatumRef ResearchEntityRef, FAstroDatumRef InstigatorEntityRef, bool& bOutSuccess) {
}

void UResearchSystem::OnResearchSubjectSet(APhysicalItem* Item) {
}

void UResearchSystem::OnResearchSubjectReleased(APhysicalItem* Item) {
}

void UResearchSystem::OnResearchSubjectItemTypeChanged(UItemComponent* researchSubjectItemComponent, TSubclassOf<UItemType> NewItemType) {
}

void UResearchSystem::OnResearchSubjectDestroyedInSlot(APhysicalItem* Item) {
}

bool UResearchSystem::IsItemTypeUnlockedForGame(const AAstroGameState* GameState, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UResearchSystem::IsItemTypeUnlocked(const APlayerController* PlayerController, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UResearchSystem::IsItemTypeKnownForGame(const AAstroGameState* GameState, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UResearchSystem::IsItemTypeHackedForGame(const AAstroGameState* GameState, TSubclassOf<UItemType> ItemType) {
    return false;
}

float UResearchSystem::GetResearchTimeProgressRatio(const FResearchSubjectComponent& ResearchSubject) {
    return 0.0f;
}

void UResearchSystem::GetResearchSubjectTotals(const FResearchSubjectComponent& ResearchSubject, float& OutTotalPointsFromSubject, float& OutSubjectTotalResearchTime) {
}

float UResearchSystem::GetResearchPointProgressRatio(const FResearchSubjectComponent& ResearchSubject) {
    return 0.0f;
}

float UResearchSystem::GetCurrentResearchPointsPerMinute(const APlayerController* PlayerController) {
    return 0.0f;
}

float UResearchSystem::GetCurrentResearchPointBalance(const APlayerController* PlayerController) {
    return 0.0f;
}

void UResearchSystem::AuthorityGrantResearchPoints(const UObject* WorldContextObject, int32 PointsToGrant) {
}


