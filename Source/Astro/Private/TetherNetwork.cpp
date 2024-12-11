#include "TetherNetwork.h"

UTetherNetwork::UTetherNetwork() {
    this->hasOxygen = false;
    this->HaveConnectedOxygen = false;
}

void UTetherNetwork::RemoveOxygenator(UOxygenatorComponent* oxygenator) {
}

void UTetherNetwork::OnTetherConnectionDestroyed(const ASlotConnection* Connection) {
}

void UTetherNetwork::OnOxygenatorSupplyingOxygenChanged(UOxygenatorComponent* oxygenator) {
}

bool UTetherNetwork::IsSupplyingOxygenToConsumers() {
    return false;
}


