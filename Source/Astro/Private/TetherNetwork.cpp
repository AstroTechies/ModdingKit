#include "TetherNetwork.h"

class UOxygenatorComponent;
class ASlotConnection;

void UTetherNetwork::RemoveOxygenator(UOxygenatorComponent* oxygenator) {
}

void UTetherNetwork::OnTetherConnectionDestroyed(const ASlotConnection* Connection) {
}

void UTetherNetwork::OnOxygenatorSupplyingOxygenChanged(UOxygenatorComponent* oxygenator) {
}

bool UTetherNetwork::IsSupplyingOxygenToConsumers() {
    return false;
}

UTetherNetwork::UTetherNetwork() {
    this->hasOxygen = false;
    this->HaveConnectedOxygen = false;
}

