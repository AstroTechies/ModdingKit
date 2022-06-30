#include "SolarBody.h"
#include "Net/UnrealNetwork.h"

class ASolarBody;
class UAstroSaveCustomArchiveProxy;
class USceneComponent;

void ASolarBody::SetOrbitAxisRotation(float rads) {
}

void ASolarBody::SetNormalizedDayTime(float dayTime) {
}

void ASolarBody::SetDayLength(float newDayLength) {
}

void ASolarBody::SetBodyTransform(const FTransform& Transform) {
}

void ASolarBody::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void ASolarBody::OnRep_OrbitAxis() {
}

void ASolarBody::OnLocalPlayerPlanetSelectionEnd() {
}

void ASolarBody::OnLocalPlayerPlanetSelectionBegin(ASolarBody* homeSolarBody) {
}

void ASolarBody::OnLocalPlayerLocalSolarBodyChanged(ASolarBody* newLocalSolarBody) {
}

void ASolarBody::OnCreativeModeEnabledChanged(bool CreativeModeEnabled) {
}

USceneComponent* ASolarBody::GetProxyComponent() {
    return NULL;
}

FVector ASolarBody::GetProxyCenter() const {
    return FVector{};
}

FVector ASolarBody::GetOrbitAxis() {
    return FVector{};
}

float ASolarBody::GetNormalizedDayTime() const {
    return 0.0f;
}

float ASolarBody::GetLastOrbitAxisRotation() const {
    return 0.0f;
}

FRotator ASolarBody::GetDayRotationOffset() const {
    return FRotator{};
}

USceneComponent* ASolarBody::GetCenterComponent() {
    return NULL;
}

FVector ASolarBody::GetCenter() const {
    return FVector{};
}

FTransform ASolarBody::GetBodyTransform() const {
    return FTransform{};
}

bool ASolarBody::CanBeVisitedByPlayer() const {
    return false;
}

void ASolarBody::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASolarBody, Gravity);
    DOREPLIFETIME(ASolarBody, DayLength);
    DOREPLIFETIME(ASolarBody, ActiveOrbitAxis);
    DOREPLIFETIME(ASolarBody, DayTimeBias);
}

ASolarBody::ASolarBody() {
    this->IconMesh = NULL;
    this->WidgetIcon = NULL;
    this->TooltipResourceObjectBadge = NULL;
    this->WorldSize = 100000.00f;
    this->GravityType = EGravityType::Spherical;
    this->GravityCylinderHeight = 0.00f;
    this->Gravity = 6.50f;
    this->GravityRadius = 0.00f;
    this->OrbitalMass = 1.00f;
    this->DayLength = 420.00f;
    this->SecondsPerSkyboxRevolution = 0.00f;
    this->FreezeOrbit = false;
    this->Stationary = false;
    this->OrbitingBody = NULL;
    this->OrbitDistance = 0.00f;
    this->LastCalculatedNormalizedDayTime = 0.00f;
    this->DayTimeBias = 0.00f;
    this->LastSetOrbitAxisRotation = 0.00f;
}

