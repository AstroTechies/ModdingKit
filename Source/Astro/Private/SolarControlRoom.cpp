#include "SolarControlRoom.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ClickableComponent.h"
#include "TooltipComponent.h"

ASolarControlRoom::ASolarControlRoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ControlRoomMesh"));
    this->GateStationOrbitDistance = 0.00f;
    this->UnlockingMissionID = TEXT("Chronos002");
    this->SelectedAudioEvent = TEXT("play_planetselect_sun_target");
    this->ControlRoomMesh = (UStaticMeshComponent*)RootComponent;
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("ToolTip"));
    this->ClickCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ClickCollisionSphere"));
    this->ProxyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProxyMesh"));
    this->ProxyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ProxyRoot"));
    this->ProxyMeshScale = 10.00f;
    this->ClickCollisionSphere->SetupAttachment(ProxyMesh);
    this->ProxyMesh->SetupAttachment(ProxyRoot);
    this->ProxyRoot->SetupAttachment(RootComponent);
}

void ASolarControlRoom::UnlockSolarControlRoom() {
}

void ASolarControlRoom::SetActualVisibility(bool bIsVisible) {
}

void ASolarControlRoom::OnMissionsInitialized() {
}

void ASolarControlRoom::OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed) {
}


void ASolarControlRoom::InitializeForSolarSystem(USolarSystem* SolarSystem) {
}

void ASolarControlRoom::HandleMissionComplete(FName missionId) {
}

void ASolarControlRoom::HandleCreativeModeEnabledChanged(bool bIsEnabled) {
}


bool ASolarControlRoom::GetIsUnlocked() {
    return false;
}


