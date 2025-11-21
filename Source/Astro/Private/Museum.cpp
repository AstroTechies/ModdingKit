#include "Museum.h"
#include "Net/UnrealNetwork.h"

AMuseum::AMuseum(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PowerUnitsNeededPerDonationReward = 5.00f;
    this->PowerTolerance = 0.02f;
    this->SinkValues = NULL;
    this->PowerConsumption = 0;
    this->ByteConsumption = 0;
    this->TotalBytesSunk = 0;
    this->TotalSeedSinkScore = 0;
    this->TotalResourceSinkScore = 0;
    this->NextResourceMilestoneIndex = 0;
    this->NextSeedMilestoneIndex = 0;
    this->NextByteMilestoneIndex = 0;
    this->NextPowerMilestoneIndex = 0;
    this->bIsResourceMilestoneComplete = false;
    this->bIsSeedMilestoneComplete = false;
    this->bIsByteMilestoneComplete = false;
    this->bIsPowerMilestoneComplete = false;
    this->bAreAllMilestonesComplete = false;
    this->bHasSaveData = false;
    this->PowerBroadcastRate = 5;
    this->REP_TotalPowerSunk = 0.00f;
    this->TotalPowerSunk = 0.00f;
    this->ConsumptionRate = 1.00f;
    this->CanisterConsumptionRateMultiplier = 10.00f;
    this->SpawnedItemOffsetMultiplier = 1.20f;
    this->REP_PowerSatisfactionThisFrame = 0.00f;
    this->PowerRequiredForBuffs = 0.00f;
}

void AMuseum::SetSeedSlotFromRef(const FSlotReference& inSlotRef) {
}

void AMuseum::SetResourceSlotFromRef(const FSlotReference& inSlotRef) {
}

void AMuseum::SendEventToServerToClearButton() {
}

void AMuseum::PresentToastNotificationForMilestone(const FText inTitle) {
}

void AMuseum::OnSlotEvent(APhysicalItem* inItem) {
}

void AMuseum::OnRep_TotalSeedSinkScore() const {
}

void AMuseum::OnRep_TotalResourceSinkScore() const {
}

void AMuseum::OnRep_TotalPowerSunk() const {
}

void AMuseum::OnRep_TotalBytesSunk() const {
}

void AMuseum::OnRep_PowerSatisfactionThisFrame() const {
}

void AMuseum::OnRep_PowerConsumption() const {
}

void AMuseum::OnRep_NextSeedMilestoneIndex() const {
}

void AMuseum::OnRep_NextResourceMilestoneIndex() const {
}

void AMuseum::OnRep_NextPowerMilestoneIndex() const {
}

void AMuseum::OnRep_NextByteMilestoneIndex() const {
}





void AMuseum::OnRep_ByteConsumption() const {
}

void AMuseum::OnItemUnslotted(APhysicalItem* inItem) {
}

void AMuseum::OnItemSlotted(APhysicalItem* inItem) {
}

bool AMuseum::IsValidMilestoneIndex(const ESinkType inSinkType, const uint8 inIndex) const {
    return false;
}

int64 AMuseum::GetTotalSeedSinkScore() const {
    return 0;
}

int64 AMuseum::GetTotalResourceSinkScore() const {
    return 0;
}

float AMuseum::GetTotalPowerSunk() const {
    return 0.0f;
}

int64 AMuseum::GetTotalByteConsumption() const {
    return 0;
}

float AMuseum::GetPowerRequiredForBuffs() const {
    return 0.0f;
}

int32 AMuseum::GetPowerConsumption() const {
    return 0;
}

float AMuseum::GetPercentage_Helper(const int64 inCurrent, const int64 inGoal) const {
    return 0.0f;
}

uint8 AMuseum::GetNextSeedMilestone() const {
    return 0;
}

uint8 AMuseum::GetNextResourceMilestone() const {
    return 0;
}

uint8 AMuseum::GetNextPowerMilestone() const {
    return 0;
}

uint8 AMuseum::GetNextByteMilestone() const {
    return 0;
}

UMuseumSinkMilestones* AMuseum::GetMilestoneData(const ESinkType inSinkType) {
    return NULL;
}

int32 AMuseum::GetByteConsumption() const {
    return 0;
}

bool AMuseum::GetAreAllSeedMilestonesComplete() const {
    return false;
}

bool AMuseum::GetAreAllResourceMilestonesComplete() const {
    return false;
}

bool AMuseum::GetAreAllPowerMilestonesComplete() const {
    return false;
}

bool AMuseum::GetAreAllByteMilestonesComplete() const {
    return false;
}

void AMuseum::ClaimReward(const ESinkType inSinkType, const uint8 inMilestoneIndex, const FTransform& inDropPosition) {
}

void AMuseum::AuthoritySetPowerConsumption(const int32 inPowerConsumption) {
}

void AMuseum::AuthoritySetByteConsumption(const int32 inByteConsumption) {
}

void AMuseum::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMuseum, ClaimableResourceMilestones);
    DOREPLIFETIME(AMuseum, ClaimableByteMilestones);
    DOREPLIFETIME(AMuseum, ClaimablePowerMilestones);
    DOREPLIFETIME(AMuseum, ClaimableSeedMilestones);
    DOREPLIFETIME(AMuseum, PowerConsumption);
    DOREPLIFETIME(AMuseum, ByteConsumption);
    DOREPLIFETIME(AMuseum, TotalBytesSunk);
    DOREPLIFETIME(AMuseum, TotalSeedSinkScore);
    DOREPLIFETIME(AMuseum, TotalResourceSinkScore);
    DOREPLIFETIME(AMuseum, NextResourceMilestoneIndex);
    DOREPLIFETIME(AMuseum, NextSeedMilestoneIndex);
    DOREPLIFETIME(AMuseum, NextByteMilestoneIndex);
    DOREPLIFETIME(AMuseum, NextPowerMilestoneIndex);
    DOREPLIFETIME(AMuseum, REP_TotalPowerSunk);
    DOREPLIFETIME(AMuseum, REP_PowerSatisfactionThisFrame);
    DOREPLIFETIME(AMuseum, PowerRequiredForBuffs);
}


