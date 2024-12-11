#include "CrystalRefineryModuleComponent.h"

UCrystalRefineryModuleComponent::UCrystalRefineryModuleComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputItemType = NULL;
    this->OutputItemType = NULL;
}

void UCrystalRefineryModuleComponent::UpdateIndicators() {
}

bool UCrystalRefineryModuleComponent::CanPerformConversion() {
    return false;
}


