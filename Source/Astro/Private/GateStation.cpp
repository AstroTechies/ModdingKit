#include "GateStation.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ActorEntityLinkComponent.h"
#include "ActorGateObjectComponent.h"
#include "ClickableComponent.h"
#include "TooltipComponent.h"

AGateStation::AGateStation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StationMesh"));
    this->StationMesh = (UStaticMeshComponent*)RootComponent;
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
    this->ClickCollisionSphere->SetupAttachment(ProxyMesh);
    this->ProxyMesh->SetupAttachment(ProxyRoot);
    this->ProxyRoot->SetupAttachment(RootComponent);
    this->TeleporterPositioningComponent->SetupAttachment(RootComponent);
}

void AGateStation::OnOutroCinematicStarted() {
}

void AGateStation::OnOutroCinematicCompleted() {
}

void AGateStation::OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed) {
}




