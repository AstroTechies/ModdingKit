#include "FlyingDroneAnimInstance.h"

UFlyingDroneAnimInstance::UFlyingDroneAnimInstance() {
    this->Speed = 50.00f;
    this->Strafe = 50.00f;
    this->SpeedStrafeLerpStrength = 0.12f;
    this->MovementComponent = NULL;
}

