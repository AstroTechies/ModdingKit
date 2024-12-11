#include "ReplicatedBrushState.h"

FReplicatedBrushState::FReplicatedBrushState() {
    this->TerrainBrushActive = false;
    this->bTerrainBrushCanUse = false;
    this->CurrentBrushIndicatorUsing = 0.00f;
    this->CurrentBrushIndicatorIntensity = 0.00f;
    this->CurrentBrushIndicatorScale = 0.00f;
    this->CurrentOperation = EDeformType::Subtract;
    this->SedimentGaugePercent = 0.00f;
    this->TotalSedimentCapacity = 0.00f;
}

