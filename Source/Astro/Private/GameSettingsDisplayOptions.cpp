#include "GameSettingsDisplayOptions.h"

FGameSettingsDisplayOptions::FGameSettingsDisplayOptions() {
    this->WindowModeOpt = EAstroWindowMode::Fullscreen;
    this->VSyncOpt = false;
    this->CurrentResolutionIndex = 0;
    this->BrightnessOpt = 0;
}

