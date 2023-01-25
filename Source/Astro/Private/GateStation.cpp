#include "GateStation.h"
#include "Components/SceneComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ActorEntityLinkComponent.h"
#include "ActorGateObjectComponent.h"
#include "ClickableComponent.h"
#include "TooltipComponent.h"

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

