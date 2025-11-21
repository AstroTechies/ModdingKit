#include "TrueFlatPlatform.h"

ATrueFlatPlatform::ATrueFlatPlatform(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->voxelVolume = NULL;
}

void ATrueFlatPlatform::OnDeformationComplete(const FDeformationParamsT2& params) {
}


