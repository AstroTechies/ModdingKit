#include "PlanetStatics.h"

UPlanetStatics::UPlanetStatics() {
}

FVector UPlanetStatics::ToPlanet(AAstroPlanet* Planet, AActor* Actor) {
    return FVector{};
}

FVector UPlanetStatics::TargetVelocity(FVector Velocity, AActor* Actor, float Time) {
    return FVector{};
}

void UPlanetStatics::TargetFacingUp(FVector Up, AActor* Actor, float TorqueStrength) {
}

void UPlanetStatics::TargetBody(ASolarBody* Body, AActor* Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer) {
}

FVector UPlanetStatics::SunDirectionRelativeToSolarBody(UObject* WorldContextObject, const ASolarBody* centerBody, const FVector& WorldPosition) {
    return FVector{};
}

FVector UPlanetStatics::SunDirection(UObject* WorldContextObject, const FVector& WorldPosition) {
    return FVector{};
}

void UPlanetStatics::SoftLanding(AAstroPlanet* Planet, AActor* Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer) {
}

FVector UPlanetStatics::PlanetUpComponent(USceneComponent* Component) {
    return FVector{};
}

FVector UPlanetStatics::PlanetUp(const UObject* WorldContextObject, const FVector& WorldPosition) {
    return FVector{};
}

bool UPlanetStatics::PlanetTrace(AActor* Actor, FHitResult& OutHit) {
    return false;
}

bool UPlanetStatics::IsTerrainReadyAtLocation(UObject* WorldContextObject, const FVector& Location) {
    return false;
}

FVector UPlanetStatics::GravityUp(const AActor* Actor) {
    return FVector{};
}

ASun* UPlanetStatics::GetSun(UObject* WorldContextObject) {
    return NULL;
}

ASolarBody* UPlanetStatics::GetSolarBodyByLocation(const UObject* WorldContextObject, FVector Location, bool bDoBoundsCheck, bool bVisitableByPlayerOnly) {
    return NULL;
}

ASolarBody* UPlanetStatics::GetSolarBody(AActor* Actor, bool bBoundsCheck) {
    return NULL;
}

TArray<AAstroPlanet*> UPlanetStatics::GetPlanets(UObject* WorldContextObject) {
    return TArray<AAstroPlanet*>();
}

EPlanetIdentifier UPlanetStatics::GetPlanetIdentifier(AActor* Actor) {
    return EPlanetIdentifier::None;
}

AAstroPlanet* UPlanetStatics::GetPlanetByLocation(const UObject* WorldContextObject, FVector Position, bool boundsCheck, bool locationIsSolar) {
    return NULL;
}

AAstroPlanet* UPlanetStatics::GetPlanetByID(UObject* WorldContextObject, EPlanetIdentifier ID) {
    return NULL;
}

AAstroPlanet* UPlanetStatics::GetPlanet(AActor* Actor, bool bBoundsCheck) {
    return NULL;
}

AGateStation* UPlanetStatics::GetGateStation(UObject* WorldContextObject) {
    return NULL;
}

AAstroPlanet* UPlanetStatics::GetClosestPlanet(const AActor* Actor) {
    return NULL;
}

FVector UPlanetStatics::GetBodyGravityAtLocation(ASolarBody* Body, FVector Location) {
    return FVector{};
}

FVector UPlanetStatics::GetBodyGravity(ASolarBody* Body, AActor* Actor) {
    return FVector{};
}

void UPlanetStatics::GeneratePlanetGravitySources(UObject* WorldContextObject) {
}

FVector UPlanetStatics::FromPlanet(AAstroPlanet* Planet, AActor* Actor) {
    return FVector{};
}

bool UPlanetStatics::EscapedBodyByLocation(ASolarBody* Body, const FVector& Location, float Scale, float Distance, bool locationIsSolar) {
    return false;
}

bool UPlanetStatics::EscapedBody(ASolarBody* Body, AActor* Actor, float Scale, float Distance) {
    return false;
}

bool UPlanetStatics::AreAtmosphericResourcesEqual(const FAtmosphericResource& resourceA, const FAtmosphericResource& resourceB) {
    return false;
}


