#include "SelectionIndicatorComponent.h"

USelectionIndicatorComponent::USelectionIndicatorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OtherActor = NULL;
    this->IgnoreSelf = false;
    this->Indicate = true;
}


