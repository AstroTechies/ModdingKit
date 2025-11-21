#include "SplinePost.h"
#include "ActuatorComponent.h"
#include "Net/UnrealNetwork.h"

USplinePost::USplinePost(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OverlapFrontComponentOverride = NULL;
    this->OverlapBackComponentOverride = NULL;
    this->GaugeDynamicMaterialIndex = -1;
    this->ActuatorComponent = CreateDefaultSubobject<UActuatorComponent>(TEXT("Actuator"));
    this->GaugeMaterial = NULL;
    this->bIsMovable = true;
    this->bHasBeenInitialized = false;
}

void USplinePost::ServerSetIsSnappedToSpline_Implementation() {
}

void USplinePost::OnRep_IsMovable() const {
}

void USplinePost::OnAsyncMapLoadStarted(const FURL& URL) {
}

void USplinePost::MulticastSetConnectionState_Implementation(ESplineConnectionState ConnectionState) {
}

void USplinePost::HandleSplineNetworkCreated() {
}

void USplinePost::HandlePowerChanged(const FStreamingPowerNodeVisualizationData& powerData) {
}

void USplinePost::HandlePickedUp(bool isPhysicalMovement) {
}

void USplinePost::HandleIsAttachedToTerrainChanged() {
}

void USplinePost::HandleDroppedDelayed() {
}

void USplinePost::HandleDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void USplinePost::HandleDeformCompleted(float DensityDelta) {
}

void USplinePost::AuthorityHandleOxygenChanged(bool hasOxygen) {
}

void USplinePost::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USplinePost, bIsMovable);
}


