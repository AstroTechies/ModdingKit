#include "ActuatorConnectorRef.h"

FActuatorConnectorRef::FActuatorConnectorRef() {
    this->ConnectorIndex = 0;
    this->bIsRerouteNode = false;
    this->ActuatorChannel = EActuatorChannel::None;
}

