#include "MegaStructureDeconstructor.h"
#include "Net/UnrealNetwork.h"

AMegaStructureDeconstructor::AMegaStructureDeconstructor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DeconstructorTargetState = EDeconstructionTargetState::None;
    this->ItemTypeDeconstructionWhitelist = NULL;
    this->DeconstructableSlottedItemsList = NULL;
    this->DeconstructionDuration = 10.00f;
    this->MidDeconstructionTime = 3.00f;
    this->DeconstructionTarget = NULL;
    this->ExoPaletteMaterial = NULL;
    this->DestructorMaterial = NULL;
    this->DeconstructorGreyMaterial = NULL;
}

void AMegaStructureDeconstructor::UpdateTargetMaterialParams(const FName param1Name, const float param1Value, const FName param2Name, const float param2Value) {
}

void AMegaStructureDeconstructor::UpdateDeconstructorTarget() {
}

void AMegaStructureDeconstructor::SetTargetMaterials() {
}

void AMegaStructureDeconstructor::OnRep_DeconstructableItems() {
}



void AMegaStructureDeconstructor::NetMulticastBeginDeconstruction_Implementation() {
}

void AMegaStructureDeconstructor::DisableTargetCollision() {
}

void AMegaStructureDeconstructor::AuthMidDeconstruction() {
}

void AMegaStructureDeconstructor::AuthEndDeconstruction() {
}

void AMegaStructureDeconstructor::AuthBeginDeconstruction() {
}

void AMegaStructureDeconstructor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMegaStructureDeconstructor, DeconstructorTargetState);
    DOREPLIFETIME(AMegaStructureDeconstructor, DeconstructableItems);
}


