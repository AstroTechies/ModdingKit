#include "GameSettingsControlsOptions.h"

FGameSettingsControlsOptions::FGameSettingsControlsOptions() {
    this->CameraMouseYAxisInverted = false;
    this->CameraGamepadYAxisInverted = false;
    this->HoldToSprintMouse = false;
    this->HoldToSprintGamepad = false;
    this->HoldToOrbitCamera = false;
    this->HoldToVirtualCursorGamepad = false;
    this->MouseSensitivity = 0;
    this->VehiclesUseAbosluteSteering = false;
    this->VehiclesUseYawAirControls = false;
    this->ToggleSpeakerGamepad = false;
    this->ToggleLightBarGamepad = false;
    this->ToggleRumbleGamepad = false;
}

