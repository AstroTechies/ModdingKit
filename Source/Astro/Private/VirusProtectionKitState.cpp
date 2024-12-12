#include "VirusProtectionKitState.h"

FVirusProtectionKitState::FVirusProtectionKitState() {
    this->IsRootKitInstalled = false;
    this->IsCounterhackKeySubmitted = false;
    this->VirusProtectionLevel = 0;
    this->SubmittedStormDataCount = 0;
}

