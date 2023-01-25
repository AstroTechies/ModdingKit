#include "AstroPlayerState.h"
#include "ActorEntityLinkComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UItemType;

void AAstroPlayerState::SetHelpMenuState(bool HelpMenuOpen) {
}

void AAstroPlayerState::OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItemTypes) {
}

void AAstroPlayerState::OnAuthorityResearchPointBalanceChanged(float NewPointBalance) {
}

void AAstroPlayerState::OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItemTypes) {
}

bool AAstroPlayerState::IsPlayerOffworld() const {
    return false;
}

EPlayerPlatform AAstroPlayerState::GetPlayerPlatform() const {
    return EPlayerPlatform::Unknown;
}

bool AAstroPlayerState::GetHelpMenuWasViewed() const {
    return false;
}

void AAstroPlayerState::BroadcastUnlockedItemTypesChanged() {
}

void AAstroPlayerState::BroadcastResearchPointBalanceChanged() {
}

void AAstroPlayerState::BroadcastKnownItemTypesChanged() {
}

void AAstroPlayerState::AuthorityNotifyAcquiredTerrainTool() {
}

void AAstroPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroPlayerState, Platform);
    DOREPLIFETIME(AAstroPlayerState, CurrentResearchPointBalance);
    DOREPLIFETIME(AAstroPlayerState, CurrentResearchPointsPerMinute);
    DOREPLIFETIME(AAstroPlayerState, KnownItemTypes);
    DOREPLIFETIME(AAstroPlayerState, UnlockedItemTypes);
}

AAstroPlayerState::AAstroPlayerState() {
    this->Platform = EPlayerPlatform::Unknown;
    this->HelpMenuWasViewed = false;
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("EntityLink"));
    this->CurrentResearchPointBalance = 0.00f;
    this->CurrentResearchPointsPerMinute = 0.00f;
    this->bAuthorityHasAcquiredTerrainTool = false;
    this->bIsOffworld = false;
    this->bIsWaitingForOutro = false;
}

