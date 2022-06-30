#include "WheeledChassisAnimInstance.h"

UWheeledChassisAnimInstance::UWheeledChassisAnimInstance() {
    this->WheelRotationScale = 0.45f;
    this->WheelMaxSteerAngle = 40.00f;
    this->WheelColliderToHubInwardPositionOffset = 30.00f;
    this->ChassisComponent = NULL;
    this->MovementComponent = NULL;
}

