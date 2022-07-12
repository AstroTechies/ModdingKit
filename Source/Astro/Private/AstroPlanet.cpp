#include "AstroPlanet.h"
#include "Net/UnrealNetwork.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=VoxelVolumeComponent -FallbackName=VoxelVolumeComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ChildActorComponent -FallbackName=ChildActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

class ASolarBody;
class ADayNight;
class APlanetProxyActor;

void AAstroPlanet::UpdateHasPlayersOnPlanet(ASolarBody* SolarBody) {
}

FLinearColor AAstroPlanet::SampleFog(const FVector& Origin, const FVector& Ray) {
    return FLinearColor{};
}

void AAstroPlanet::OnDeformationComplete(const FDeformationParamsT2& params) {
}

bool AAstroPlanet::LocationInAtmosphere(const FVector& Location) {
    return false;
}

FVector AAstroPlanet::GetWindDirectionAt(const FVector& Location, float& Intensity) {
    return FVector{};
}

FVector AAstroPlanet::GetTerrainNormal(const FVector& Location) {
    return FVector{};
}

FVoxelMaterial AAstroPlanet::GetTerrainMaterial(const FVector& Location) {
    return FVoxelMaterial{};
}

float AAstroPlanet::GetTerrainDensity(const FVector& Location) {
    return 0.0f;
}

float AAstroPlanet::GetRadius() const {
    return 0.0f;
}

APlanetProxyActor* AAstroPlanet::GetProxy() {
    return NULL;
}

FTransform AAstroPlanet::GetPlanetTransform() {
    return FTransform{};
}

FTransform AAstroPlanet::GetPlanetToProxyTransform() {
    return FTransform{};
}

FVector AAstroPlanet::GetNorthVector() {
    return FVector{};
}

ADayNight* AAstroPlanet::GetDayNightActor() const {
    return NULL;
}

void AAstroPlanet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroPlanet, NavpointManagerOwner);
}

AAstroPlanet::AAstroPlanet() {
    this->PlanetIdentifier = EPlanetIdentifier::None;
    this->PlanetItemType = NULL;
    this->PlanetaryVoxelVolume = NULL;
    this->DefaultVoxelVolume = CreateDefaultSubobject<UVoxelVolumeComponent>(TEXT("Default Voxel Volume"));
    this->Seed = 343;
    this->VerticalZLandingZone = false;
    this->Enable = true;
    this->Difficulty = 0;
    this->Cutaway = false;
    this->CenterOrigin = false;
    this->RandomizeSeedForBuild = true;
    this->RandomizeSeedForPIE = false;
    this->LodMultiplier = 1.60f;
    this->VoxelSize = 150.00f;
    this->SunExposureModifier = 1.00f;
    this->WindIntensityModifier = 1.00f;
    this->AmbientIntensity = 0.50f;
    this->DaytimeSkyIntensity = 1.00f;
    this->NightSkyIntensity = 0.20f;
    this->FogFalloff = 100000.00f;
    this->FogPower = 1.00f;
    this->FogAtmosphereHeight = 5000.00f;
    this->FogAtmosphereThickness = 10000.00f;
    this->DaytimeEnvironmentFogContribution = 0.50f;
    this->NighttimeEnvironmentFogContribution = 0.50f;
    this->FogUndergroundThickness = 2.50f;
    this->FogMaxOpacity = 0.10f;
    this->FogSunHaloIntensity = 2.00f;
    this->FogSunHaloPower = 5.00f;
    this->WindScale = 0.00f;
    this->WindNoiseMovement = 100.00f;
    this->WindDirectionChangeRate = 300.00f;
    this->WindIntensityChangeRate = 1000.00f;
    this->AmbientWind = 0.33f;
    this->MaxFlightHeightAdjustment = 0.00f;
    this->FogMaterialDynamic = NULL;
    this->FogMaterialParameterCollection = NULL;
    this->IsLocallyVisible = true;
    this->FogMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FogActor"));
    this->ProxyComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Proxy Component"));
    this->ProxyMeshComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Proxy Mesh Component"));
    this->LowRezClouds = NULL;
    this->LowRezProxyClouds = NULL;
    this->AtmostphericFeatures = NULL;
    this->SunActor = NULL;
    this->DayNightActor = NULL;
    this->NavpointManagerOwner = NULL;
}

