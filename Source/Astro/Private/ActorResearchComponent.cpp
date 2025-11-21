#include "ActorResearchComponent.h"
#include "Net/UnrealNetwork.h"

UActorResearchComponent::UActorResearchComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ResearchPowerRequired = 4.00f;
    this->MinimumResearchPowerFraction = 1.00f;
    this->MinimumResearchRateMultiplier = 1.00f;
    this->UnderPoweredResearchRateCurve = NULL;
    this->MaximumResearchPowerMultiplier = 1.00f;
    this->MaximumResearchRateMutliplier = 1.00f;
    this->OverPoweredResearchRateCurve = NULL;
    this->bResearchSlotsUnclickableWhileActive = true;
    this->bDestroyActiveResearchSubjectsOnInterruption = true;
    this->ExpiredResearchSubjectDestructionDelay = 3.00f;
}

void UActorResearchComponent::OnRep_ResearchData() {
}

bool UActorResearchComponent::AuthorityStartOrInterruptResearch(APlayController* InstigatingController) {
    return false;
}

void UActorResearchComponent::AuthorityChangedActiveResearchSubjects(FAstroDatumRef ResearchComponentRef, const TArray<FAttachedResearchSubject>& ActiveResearchSubjects) {
}

void UActorResearchComponent::AuthorityActiveResearchSubjectExpired(FAstroDatumRef ResearchComponentRef, FAttachedResearchSubject ExpiredAttachedResearchSubject) {
}

void UActorResearchComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorResearchComponent, ResearchReplicationData);
}


