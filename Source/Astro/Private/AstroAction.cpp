#include "AstroAction.h"

UAstroAction::UAstroAction() {
    this->RequiredResources = 0;
    this->Priority = 0;
    this->bInterruptedBySamePriority = false;
    this->State = EAstroActionState::Inactive;
}

