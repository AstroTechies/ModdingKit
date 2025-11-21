#include "OrbitalNavigationComponent.h"
#include "Net/UnrealNetwork.h"

UOrbitalNavigationComponent::UOrbitalNavigationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bPreventRespawnWhileDriving = false;
    this->LaunchLength = 15.00f;
    this->DefaultOrbitSpeed = 0.04f;
    this->MinOrbitSpeed = 0.01f;
    this->MaxOrbitSpeed = 0.25f;
    this->OrbitSpeedRangeStep = 0.20f;
    this->OrbitSpeedTransitionRate = 0.00f;
    this->OrbitSpeedInputRepeatDelay = 0.20f;
    this->UseLaunchUpVector = true;
    this->OrbitDistance = 1.69f;
    this->EasePower = 5.00f;
    this->LerpPower = 0.50f;
    this->PhysicsDisabled = false;
    this->SelectedTarget = NULL;
    this->LaunchTime = 0.00f;
    this->planetSelection = false;
    this->shouldLaunchUpdate = false;
    this->SourceTime = 0.00f;
    this->TargetTime = 0.00f;
    this->CurrentTime = 0.00f;
    this->storage = NULL;
    this->CurrOrbitGameSpeedScalarDegree = 0.00f;
    this->REP_TargetOrbitGameSpeedScalarDegree = 0.12f;
    this->Local_TargetOrbitGameSpeedScalarDegree = 0.00f;
    this->DefaultOrbitSpeedScalarDegree = 0.12f;
    this->InterplanetaryTravelRange = 3000000.00f;
    this->SourceSolarBody = NULL;
    this->TimeSinceLastOrbitSpeedChange = 0.00f;
    this->CurrOrbitSpeedInput = 0;
    this->DiscreteOrbitSpeedInput = 0;
    this->AxisOrbitSpeedInput = 0;
    this->MaxOrbitSpeedScalar = 0.00f;
    this->MinOrbitSpeedScalar = 1.00f;
}

void UOrbitalNavigationComponent::SetPlanetSelection(bool Enable) {
}

void UOrbitalNavigationComponent::SetActiveLaunchLength(float newLaunchLength) {
}

void UOrbitalNavigationComponent::ServerSetOrbitSpeedScalarDegree_Implementation(float speedScalarDegree) {
}
bool UOrbitalNavigationComponent::ServerSetOrbitSpeedScalarDegree_Validate(float speedScalarDegree) {
    return true;
}

void UOrbitalNavigationComponent::PerformLaunch(UObject* Target) {
}

void UOrbitalNavigationComponent::OnStorageAttachmentsChanged(bool Entered) {
}

void UOrbitalNavigationComponent::OnSolarBodyClick(ASolarBody* SolarBody) {
}

void UOrbitalNavigationComponent::OnRep_TargetOrbitSpeedScalarDegree() {
}

void UOrbitalNavigationComponent::OnRep_ReplicatedTimeData() {
}

void UOrbitalNavigationComponent::OnRep_ReplicatedData() {
}

void UOrbitalNavigationComponent::OnOrbitSpeedInputUpOrDown(float AxisValue) {
}

void UOrbitalNavigationComponent::OnOrbitSpeedInputUp() {
}

void UOrbitalNavigationComponent::OnOrbitSpeedInputEnd() {
}

void UOrbitalNavigationComponent::OnOrbitSpeedInputDown() {
}

void UOrbitalNavigationComponent::OnLandEndHover() {
}

void UOrbitalNavigationComponent::OnLandClick(AActor* Actor) {
}

void UOrbitalNavigationComponent::OnLandBeginHover() {
}

bool UOrbitalNavigationComponent::LocalPlayerOnBoard() {
    return false;
}

void UOrbitalNavigationComponent::HandleVehicleUnmanned(AAstroPlayerController* VehicleDriver) {
}

void UOrbitalNavigationComponent::HandleVehicleManned(AAstroPlayerController* VehicleDriver) {
}

ASolarBody* UOrbitalNavigationComponent::GetTargetOrbitingBody() {
    return NULL;
}

float UOrbitalNavigationComponent::GetOrbitSpeedPercent() {
    return 0.0f;
}

float UOrbitalNavigationComponent::GetLaunchTime() {
    return 0.0f;
}

bool UOrbitalNavigationComponent::GetLaunched() {
    return false;
}

bool UOrbitalNavigationComponent::GetLanding() {
    return false;
}

bool UOrbitalNavigationComponent::GetLanded() {
    return false;
}

bool UOrbitalNavigationComponent::GetIsInOrbit() {
    return false;
}

bool UOrbitalNavigationComponent::GetCanLaunch() {
    return false;
}

FVector UOrbitalNavigationComponent::GetCameraUpVector() {
    return FVector{};
}

void UOrbitalNavigationComponent::AuthoritySnapToTarget(UObject* Target) {
}

void UOrbitalNavigationComponent::AuthoritySetInterplanetaryTravelRangeMultiplier(float rangeMultiplier) {
}

UOrbitalNavigationComponent* UOrbitalNavigationComponent::ActorOrbitalNavigationComponent(AActor* Actor) {
    return NULL;
}

void UOrbitalNavigationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOrbitalNavigationComponent, ReplicatedData);
    DOREPLIFETIME(UOrbitalNavigationComponent, REP_TargetOrbitGameSpeedScalarDegree);
    DOREPLIFETIME(UOrbitalNavigationComponent, TimeData);
}


