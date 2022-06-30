#include "AstroPlayMontageAction.h"

class UAnimMontage;

void UAstroPlayMontageAction::SetMontage(UAnimMontage* NewMontage) {
}

void UAstroPlayMontageAction::OnSingleAnimCustomNotify(FName NotifyName) {
}

void UAstroPlayMontageAction::OnMontageTaskInterrupted() {
}

void UAstroPlayMontageAction::OnMontageTaskFailedToStart() {
}

void UAstroPlayMontageAction::OnMontageTaskCompleted() {
}

UAstroPlayMontageAction::UAstroPlayMontageAction() {
    this->Montage = NULL;
    this->PlayRate = 1.00f;
    this->bShouldSuppressLookInput = false;
    this->bShouldSuppressMoveInput = false;
    this->bChooseStartSectionAtRandom = false;
}

