#include "CellularProperties.h"

FCellularProperties::FCellularProperties() {
    this->CellType = ECellType::CellValue;
    this->Jitter = 0.00f;
    this->DistanceFunction = EDistanceFunction::Euclidean;
    this->DistanceIndex0 = 0;
    this->DistanceIndex1 = 0;
    this->LookupType = ENoiseType::Value;
    this->Frequency = 0.00f;
}

