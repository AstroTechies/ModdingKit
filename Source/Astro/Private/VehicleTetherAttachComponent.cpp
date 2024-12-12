#include "VehicleTetherAttachComponent.h"

UVehicleTetherAttachComponent::UVehicleTetherAttachComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PreviousClosestTetherPost = NULL;
    this->PreviousTetherNetwork = NULL;
}


