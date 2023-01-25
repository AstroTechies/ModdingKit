#include "CompassActor.h"

void ACompassActor::SetShown(bool isShown) {
}

void ACompassActor::HandleUserSettingsChanged() {
}

void ACompassActor::HandleOrbitalNavLaunch() {
}

void ACompassActor::HandleNavpointRemoved(const FGuid& NavpointID) {
}

void ACompassActor::HandleNavpointAdded(const FGuid& NavpointID) {
}

void ACompassActor::HandleDrivingStatusChanged() {
}

ACompassActor::ACompassActor() {
    this->RingsMeshAsset = NULL;
    this->RingsMaterialAsset = NULL;
    this->ElevationLineMesh = NULL;
    this->DistanceCurve = NULL;
    this->NavpointScaleCurve = NULL;
    this->NavpointOpacityCurve = NULL;
    this->MaxNavpointDistanceWithinCompassInterior = 60000.00f;
    this->MaxNavpointDistanceOnCompassPerimeter = 400000.00f;
    this->MaxNavpointElevationChange = 20000.00f;
    this->MaxNavpointIconDistance = 42.00f;
    this->MaxNavpointIconHeight = 120.00f;
    this->CompassRingsScale = 13.00f;
    this->NavpointScale = 2.50f;
    this->NavpointIconMeshRadius = 10.00f;
    this->NavpointIconMeshHalfHeight = 1.50f;
    this->NavpointMinScaleOnPerimeter = 0.35f;
    this->NavpointMaxScaleOnPerimeter = 0.70f;
    this->NavpointFadeTime = 0.50f;
    this->MinOpacityCutoutThreshold = 0.30f;
    this->NavpointCap = 10;
    this->RingsMaterial = NULL;
    this->Rings = NULL;
}

