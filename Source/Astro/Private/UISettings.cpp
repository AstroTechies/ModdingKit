#include "UISettings.h"

class UUISettings;

UUISettings* UUISettings::GetAstroUISettings() {
    return NULL;
}

UUISettings::UUISettings() {
    this->DisplayEarlyAccessWatermark = false;
    this->DisplayExperimentalWatermark = false;
    this->CursorSize = 55.00f;
    this->DeadZone = 0.01f;
    this->MaxSpeed = 1200.00f;
    this->MaxSpeedWhenHovered = 350.00f;
    this->MinSpeed = 0.00f;
    this->AccelerationMultiplier = 1000.00f;
    this->bHasIntertia = false;
    this->DragCoefficient = 8.00f;
    this->DragCoefficientWhenHovered = 14.00f;
}

