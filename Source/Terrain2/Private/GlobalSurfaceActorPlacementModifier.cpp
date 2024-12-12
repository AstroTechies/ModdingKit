#include "GlobalSurfaceActorPlacementModifier.h"

UGlobalSurfaceActorPlacementModifier::UGlobalSurfaceActorPlacementModifier() {
    this->PlacementLODOffset = 20;
    this->MinimumBiomeWeight = 0.40f;
    this->DefaultMinimumBiomeWeight = 0.40f;
    this->MinimumBiomeWeightReductionStep = 0.10f;
    this->MinimumBiomeWeightAddAllowedBiomesThreshhold = 0.40f;
    this->MinimumCount = 0;
    this->MaximumCount = 0;
    this->Radius = 0.00f;
}


