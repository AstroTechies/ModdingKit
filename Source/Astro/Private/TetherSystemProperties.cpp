#include "TetherSystemProperties.h"

UTetherSystemProperties::UTetherSystemProperties() {
    this->SegmentMesh = NULL;
    this->DefaultMaterial = NULL;
    this->IndicatorMaterial = NULL;
    this->NoOxygenMaterial = NULL;
    this->BreakDistance = 2550.00f;
    this->SegmentLength = 40.00f;
    this->SegmentScale = 0.27f;
    this->GravityTension = 0.20f;
    this->CurveTension = 1.00f;
    this->AdjustDistance = 4.00f;
}

