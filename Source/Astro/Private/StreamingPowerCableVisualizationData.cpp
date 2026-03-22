#include "StreamingPowerCableVisualizationData.h"

FStreamingPowerCableVisualizationData::FStreamingPowerCableVisualizationData() {
    this->FlowSpeed = 0.00f;
    this->ConsumptionRatio = 0.00f;
    this->GenerationRatio = 0.00f;
    this->CableConnectionState = ECableConnectionState::DisconnectedCable;
}

