#include "ControlPanelItemComponent.h"

UControlPanelItemComponent::UControlPanelItemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PadChannel = ELogisticsComplexChannel::None;
}


