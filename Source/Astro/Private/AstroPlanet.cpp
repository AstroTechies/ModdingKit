#include "AstroPlanet.h"
#include "Components/ChildActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "VoxelVolumeComponent.h"
#include "Net/UnrealNetwork.h"

AAstroPlanet::AAstroPlanet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->AutoReceiveInput = EAutoReceiveInput::Player0;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->OrbitingBodyName = TEXT("Sun");
    this->bAllowsCreativeFlight = true;
    this->PlanetIdentifier = EPlanetIdentifier::None;
    this->PlanetItemType = NULL;
    this->PlanetaryVoxelVolume = NULL;
    this->DefaultVoxelVolume = CreateDefaultSubobject<UVoxelVolumeComponent>(TEXT("Default Voxel Volume"));
    this->VerticalZLandingZone = false;
    this->Enable = true;
    this->Difficulty = 0;
    this->Cutaway = false;
    this->CenterOrigin = false;
    this->LodMultiplier = 1.60f;
    this->VoxelSize = 150.00f;
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
    this->UseWindIntensityDebugScalar = false;
    this->WindIntensityDebugScalar = 1.00f;
    this->AmbientWindDebugOverride = 0.00f;
    this->isStartingPlanet = false;
    this->CrustFirewallClass = NULL;
    this->MantleFirewallClass = NULL;
    this->CoreFirewallClass = NULL;
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
    this->DefaultVoxelVolume->SetupAttachment(RootComponent);
    this->FogMesh->SetupAttachment(RootComponent);
    this->ProxyComponent->SetupAttachment(RootComponent);
    this->ProxyMeshComponent->SetupAttachment(ProxyComponent);
}

void AAstroPlanet::UpdateHasPlayersOnPlanet(ASolarBody* SolarBody) {
}

void AAstroPlanet::SetIsStartingPlanet(bool NewIsStartingPlanet) {
}

void AAstroPlanet::SetCustomGamePlanetModifierData(FCustomGameModifierData& modifierData) {
}

void AAstroPlanet::SetCustomGameModifiersFromGameState() {
}

void AAstroPlanet::SetCustomGameModifiers(FCustomGameModifierCollection& ModifierCollection) {
}

FLinearColor AAstroPlanet::SampleFog(const FVector& Origin, const FVector& Ray) const {
    return FLinearColor{};
}

void AAstroPlanet::OnDeformationComplete(const FDeformationParamsT2& params) {
}

void AAstroPlanet::LogCustomGameBiomeModifiersData() {
}

bool AAstroPlanet::LocationInAtmosphere(const FVector& Location) {
    return false;
}

FVector AAstroPlanet::GetWindDirectionAt(const FVector& Location, float& Intensity, float& stormIntensity) {
    return FVector{};
}

FVector AAstroPlanet::GetTerrainNormal(const FVector& Location) {
    return FVector{};
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

bool AAstroPlanet::GetHasPrimaryBiomeAtLocation(const FString& BiomeName, const FVector& Location, float MinBiomeWeight) {
    return false;
}

ADayNight* AAstroPlanet::GetDayNightActor() const {
    return NULL;
}

void AAstroPlanet::GetCustomGamePlanetModifierData(FCustomGameModifierCollection& outData) {
}

void AAstroPlanet::ClearCustomGameState() {
}

void AAstroPlanet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroPlanet, NavpointManagerOwner);
}


