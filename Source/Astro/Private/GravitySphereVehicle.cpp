#include "GravitySphereVehicle.h"
#include "AdaptiveTickComponent.h"
#include "BallPhysicsMovementComponent.h"
#include "ControlComponent.h"
#include "PlanetEffect.h"

AGravitySphereVehicle::AGravitySphereVehicle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TurningInputBias = 5.00f;
    this->SeatFacingInputDirectionBias = 0.75f;
    this->EVA_ItemType = NULL;
    this->MaxSpeedThresholdForTopSpeedObjective = 0.90f;
    this->ControlComponent = CreateDefaultSubobject<UControlComponent>(TEXT("ControlComponent"));
    this->PlanetEffect = CreateDefaultSubobject<UPlanetEffect>(TEXT("Planet Effect"));
    this->AdaptiveTickComponent = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("AdaptiveTickComponent"));
    this->MovementComponent = CreateDefaultSubobject<UBallPhysicsMovementComponent>(TEXT("BallPhysicsMovementComponent"));
}

void AGravitySphereVehicle::SetupComponentReferences(UActorAttachmentsComponent* attachmentComponent, USceneComponent* seatRoot, USceneComponent* cameraTargetNode) {
}

void AGravitySphereVehicle::OnPilotExitComplete(AActor* pilot) {
}

void AGravitySphereVehicle::OnEffectRelevanceChanged(bool IsInRelevancy) {
}

void AGravitySphereVehicle::OnAI_ControllerReleased(APhysicalItem* controllerItem) {
}

void AGravitySphereVehicle::OnAI_ControllerAttached(APhysicalItem* controllerItem) {
}

bool AGravitySphereVehicle::IsLocallyControlled() const {
    return false;
}

void AGravitySphereVehicle::HandleVehicleUnmanned(AAstroPlayerController* OldPilot) {
}

void AGravitySphereVehicle::HandleVehicleManned(AAstroPlayerController* NewPilot) {
}

void AGravitySphereVehicle::HandleJumpInput() {
}

EGravitySphereControllerType AGravitySphereVehicle::GetAttachedControllerType() {
    return EGravitySphereControllerType::Player;
}

void AGravitySphereVehicle::AuthorityHandlePickedUp(bool PhysicalMovement) {
}


