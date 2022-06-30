#include "ActuationRequest.h"

FActuationRequest::FActuationRequest() {
    this->DelayTicks = 0;
    this->FullnessActuatorEventType = EFullnessActuatorEventType::None;
    this->addedDuringQueueIteration = false;
}

