#include "ControlPanelButton.h"

void AControlPanelButton::SetButtonEnabled(bool Enabled) {
}

void AControlPanelButton::SetButtonArmed(bool Armed) {
}

bool AControlPanelButton::GetButtonEnabled() {
    return false;
}

bool AControlPanelButton::GetButtonArmed() {
    return false;
}

void AControlPanelButton::DoUnHoverButton() {
}

void AControlPanelButton::DoHoverButton() {
}

void AControlPanelButton::DoButtonPress() {
}

AControlPanelButton::AControlPanelButton() {
    this->bHasCover = false;
    this->bCloseCoverOnUnHover = false;
    this->bCoverOpenedWhenEnabled = false;
    this->bButtonEnabled = false;
    this->bButtonArmed = false;
}

