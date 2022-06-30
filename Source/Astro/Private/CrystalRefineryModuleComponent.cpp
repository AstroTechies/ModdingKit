#include "CrystalRefineryModuleComponent.h"

void UCrystalRefineryModuleComponent::UpdateIndicators() {
}

bool UCrystalRefineryModuleComponent::CanPerformConversion() {
    return false;
}

UCrystalRefineryModuleComponent::UCrystalRefineryModuleComponent() {
    this->InputItemType = NULL;
    this->OutputItemType = NULL;
}

