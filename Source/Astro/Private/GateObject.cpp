#include "GateObject.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
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

