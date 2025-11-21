#include "AstroStorm.h"
#include "Net/UnrealNetwork.h"

AAstroStorm::AAstroStorm(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->StormID = -1;
    this->StateIndex = 0;
    this->Age = -1.00f;
    this->Lifetime = -1.00f;
    this->DelayEffectsSeconds_LevelZero = 0.00f;
    this->DelayEffectsSeconds_LevelOne = 0.00f;
    this->DelayEffectsSeconds_LevelTwo = 0.00f;
    this->DelayEffectsSeconds_LevelThree = 0.00f;
    this->OuterGameplayRadius = 0.00f;
    this->InnerGameplayRadius = 0.00f;
    this->PlayerGameplayRadius = 0.00f;
    this->WindPowerScalar = 0.00f;
    this->PlayerGlitchWallApproachDistance = 0.00f;
    this->LocalPointSpawnedFXEnabled = false;
    this->SpawnedFXStateContainersInitialized = false;
    this->StormVisualActor = NULL;
}



UParticleSystemComponent* AAstroStorm::SpawnLocalPointSpawnedFX(UParticleSystem* ParticleTemplate, FVector Position, FTransform SpawnTransform, float NewAge) {
    return NULL;
}

void AAstroStorm::SetPlayerStormRadiusState(AAstroPlayerController* PlayerController, EAstroPlayerStormRadiusStates State) {
}

void AAstroStorm::ServerPlayerExitedStorm_Implementation(AAstroPlayerController* PlayerController) {
}
bool AAstroStorm::ServerPlayerExitedStorm_Validate(AAstroPlayerController* PlayerController) {
    return true;
}

void AAstroStorm::ServerPlayerEnteredStorm_Implementation(AAstroPlayerController* PlayerController) {
}
bool AAstroStorm::ServerPlayerEnteredStorm_Validate(AAstroPlayerController* PlayerController) {
    return true;
}

void AAstroStorm::RegisterPlayerForStormEffectsTracking(AAstroPlayerController* PlayerController) {
}

void AAstroStorm::OnVirusProtectionUpdated() {
}

void AAstroStorm::OnRep_SpawnedFXStateContainers() {
}

bool AAstroStorm::IsSafeSpawnedFXLocation(FVector Location, float Radius) {
    return false;
}

void AAstroStorm::InitLocalPointSpawnedFXStateContainers() {
}

bool AAstroStorm::HasPlayerStormEffectsInfo(AAstroPlayerController* PlayerController) {
    return false;
}


float AAstroStorm::GetRubyHarvestRatio(FVector rubyLocation) {
    return 0.0f;
}

FPlayerStormEffectsInfo AAstroStorm::GetPlayerStormEffectsInfo(AAstroPlayerController* PlayerController) {
    return FPlayerStormEffectsInfo{};
}

float AAstroStorm::GetLocationGlitchWallRadiusRatio(FVector Location) {
    return 0.0f;
}

float AAstroStorm::GetLocationGameplayRadiusRatio(FVector Location) {
    return 0.0f;
}

FVector AAstroStorm::GetClosestRubyHarvestPoint(FVector rubyLocation) {
    return FVector{};
}

void AAstroStorm::ClearAllLocalPointSpawnedFX() {
}

void AAstroStorm::AuthorityUpdateLocalPointSpawnedFX(float dt) {
}



void AAstroStorm::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroStorm, StormID);
    DOREPLIFETIME(AAstroStorm, StateIndex);
    DOREPLIFETIME(AAstroStorm, Age);
    DOREPLIFETIME(AAstroStorm, Lifetime);
    DOREPLIFETIME(AAstroStorm, PlayerStormEffectsInfo);
    DOREPLIFETIME(AAstroStorm, SpawnedFXStateContainers);
}


