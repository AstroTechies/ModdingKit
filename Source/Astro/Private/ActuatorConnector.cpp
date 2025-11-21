#include "ActuatorConnector.h"

FActuatorConnector::FActuatorConnector() {
    this->TargetComponent = NULL;
    this->ParentCable = 0;
    this->bInUse = false;
    this->ActuatorChannel = EActuatorChannel::None;
}

