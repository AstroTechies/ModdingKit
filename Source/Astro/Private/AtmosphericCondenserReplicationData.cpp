#include "AtmosphericCondenserReplicationData.h"

FAtmosphericCondenserReplicationData::FAtmosphericCondenserReplicationData() {
    this->CondenserState = EAtmosphericCondenserState::Invalid;
    this->SelectedOuputResourceIndex = 0;
    this->NumPossibleProductionOutputs = 0;
    this->ProductionEfficiency = 0.00f;
    this->ProductionPowerRatio = 0.00f;
    this->CurrentHarvestedAtmosphereAmount = 0.00f;
    this->CurrentPlanet = NULL;
}

