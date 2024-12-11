#include "Scanner.h"
#include "Net/UnrealNetwork.h"

AScanner::AScanner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ScannerMode = EScannerMode::Asleep;
    this->TargetDistance = EScannerTargetDistance::NoTarget;
    this->MidRangeDistancePercentage = 0.00f;
    this->PitchAnimationValue = 0.00f;
    this->YawAnimationValue = 0.00f;
    this->ScanCooldownTimeSeconds = 0.00f;
    this->ShortRangeMaxDistance = 0.00f;
    this->MidRangeMaxDistance = 0.00f;
    this->PitchAlphaCurve = NULL;
    this->ShortRangeScanDurationSeconds = 0.00f;
    this->LongRangeScanDurationSeconds = 0.00f;
    this->MidRangeScanSpeedTransitionCurve = NULL;
    this->MidRangeScanSpeedSelectionCurve = NULL;
    this->MidRangeScanSweepCount = 0;
    this->ObfuscationYawOffsetCurve = NULL;
    this->ObfuscationYawOffsetCurveFrequency = 0.00f;
    this->MaxObfuscationYawOffsetMultiplier = 0.00f;
    this->MidRangeScanIntroAnimationLengthSeconds = 0.00f;
}

void AScanner::OnRep_UsingCharacter() {
}

void AScanner::OnRep_TargetDistance() {
}

void AScanner::OnRep_ScannerMode() {
}

void AScanner::OnRep_MidRangeDistancePercentage() {
}

void AScanner::OnPowerAvailableChanged(bool hasPower) {
}

void AScanner::OnMidRangeScanIntroAnimationCompleted() {
}

void AScanner::HandleVehicleUnmanned(AAstroPlayerController* oldUsingPlayer) {
}

void AScanner::HandleVehicleManned(AAstroPlayerController* newUsingPlayer) {
}

void AScanner::HandleReleasedFromSlot(bool NewOwner) {
}

void AScanner::HandlePlacedInSlot() {
}

void AScanner::AuthorityTryScan() {
}

void AScanner::AuthorityOnScanCompleted() {
}

void AScanner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AScanner, ScannerMode);
    DOREPLIFETIME(AScanner, TargetDistance);
    DOREPLIFETIME(AScanner, MidRangeDistancePercentage);
    DOREPLIFETIME(AScanner, CurrentTarget);
    DOREPLIFETIME(AScanner, UsingCharacter);
}


