#include "ReroutePlacementHelper.h"

AReroutePlacementHelper::AReroutePlacementHelper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = false;
    this->bAlwaysRelevant = true;
    this->IsUnslottable = true;
    this->ActuatorComponent = NULL;
}

void AReroutePlacementHelper::ServerTryDeleteNode_Implementation() {
}
bool AReroutePlacementHelper::ServerTryDeleteNode_Validate() {
    return true;
}

void AReroutePlacementHelper::OnUsePressed() {
}

void AReroutePlacementHelper::MulticastStateChange_Implementation(bool pickedUp) {
}


