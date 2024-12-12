#include "GateObject.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ActorEntityLinkComponent.h"
#include "ActorGateObjectComponent.h"

AGateObject::AGateObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
//    this->bReplicateHidden = false;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->IsGatewayStationStandin = false;
    this->StaticMesh = (UStaticMeshComponent*)RootComponent;
    this->TeleporterPositioningComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TeleporterPositioning"));
    this->GateObjectComponent = CreateDefaultSubobject<UActorGateObjectComponent>(TEXT("GateObject"));
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("ActorEntityLink"));
    this->LocalSolarBody = NULL;
    this->TeleporterPositioningComponent->SetupAttachment(RootComponent);
}

void AGateObject::OnSolarSystemInitialized(USolarSystem* SolarSystem) {
}

void AGateObject::OnLocalPlayerChangedLocalSolarBody(ASolarBody* playerLocalSolarBody) {
}


