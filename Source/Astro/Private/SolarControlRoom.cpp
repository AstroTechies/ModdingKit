#include "SolarControlRoom.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ClickableComponent.h"
#include "TooltipComponent.h"

class AActor;
class USolarSystem;

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

ASolarControlRoom::ASolarControlRoom() {
    this->GateStationOrbitDistance = 0.00f;
    this->UnlockingMissionID = TEXT("Chronos002");
    this->SelectedAudioEvent = TEXT("play_planetselect_sun_target");
    this->ControlRoomMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ControlRoomMesh"));
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("ToolTip"));
    this->ClickCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ClickCollisionSphere"));
    this->ProxyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProxyMesh"));
    this->ProxyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ProxyRoot"));
    this->ProxyMeshScale = 10.00f;
}

