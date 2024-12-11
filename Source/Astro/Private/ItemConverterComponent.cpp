#include "ItemConverterComponent.h"

FItemConverterComponent::FItemConverterComponent() {
    this->bWantsToBeActive = false;
    this->ConverterState = EItemConverterState::Inactive;
    this->ActiveConversionIDCounter = 0;
    this->SelectedOutputItemTypeIndex = 0;
}

