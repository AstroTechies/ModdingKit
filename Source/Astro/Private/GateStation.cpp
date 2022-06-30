#include "GateStation.h"
#include "ActorGateObjectComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ClickableComponent.h"
#include "Components/SceneComponent.h"
#include "TooltipComponent.h"
#include "Components/SphereComponent.h"
#include "ActorEntityLinkComponent.h"

class AActor;

void AGateStation::OnOutroCinematicStarted() {
}

void AGateStation::OnOutroCinematicCompleted() {
}

void AGateStation::OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed) {
}


AGateStation::AGateStation() {
    this->StationMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StationMesh"));
    this->TeleporterPositioningComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TeleporterPositioning"));
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("ToolTip"));
    this->ClickCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ClickCollisionSphere"));
    this->ProxyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProxyMesh"));
    this->ProxyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ProxyRoot"));
    this->ProxyMeshScale = 10.00f;
    this->GateObjectComponent = CreateDefaultSubobject<UActorGateObjectComponent>(TEXT("GateObject"));
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("ActorEntityLink"));
    this->StationIndicatorDefinitions = NULL;
}

