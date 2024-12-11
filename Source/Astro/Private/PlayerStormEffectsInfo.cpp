#include "PlayerStormEffectsInfo.h"

FPlayerStormEffectsInfo::FPlayerStormEffectsInfo() {
    this->DelayBeforeApplyingEffectsSeconds = 0.00f;
    this->DelayBeforeApplyingEffectsCounter = 0.00f;
    this->PlayerStormRadiusState = EAstroPlayerStormRadiusStates::OutsideStorm;
    this->bEffectsApplied = false;
}

