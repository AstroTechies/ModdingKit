#include "MiniPlanet.h"

AMiniPlanet::AMiniPlanet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->voxelVolume = NULL;
    this->LowRezCloudsClass = NULL;
    this->LowRezProxyCloudsClass = NULL;
    this->AtmosphericFeaturesClass = NULL;
    this->LowRezCloudsActorRef = NULL;
    this->LowRezProxyCloudsActorRef = NULL;
    this->AtmosphericFeaturesActorRef = NULL;
    this->bIsPendingDeletion = false;
}

void AMiniPlanet::OnDeformationComplete(const FDeformationParamsT2& params) {
}


