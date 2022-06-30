#include "GateObject.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ActorGateObjectComponent.h"
#include "ActorEntityLinkComponent.h"

class USolarSystem;
class ASolarBody;

void AGateObject::OnSolarSystemInitialized(USolarSystem* SolarSystem) {
}

void AGateObject::OnLocalPlayerChangedLocalSolarBody(ASolarBody* playerLocalSolarBody) {
}

AGateObject::AGateObject() {
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->TeleporterPositioningComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TeleporterPositioning"));
    this->GateObjectComponent = CreateDefaultSubobject<UActorGateObjectComponent>(TEXT("GateObject"));
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("ActorEntityLink"));
    this->LocalSolarBody = NULL;
}

