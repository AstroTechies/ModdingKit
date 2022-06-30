#include "AstroCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "AstroActionComponent.h"
#include "AstroPlayMontageAction.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

class UItemType;
class ABackpack;
class UChildActorComponent;
class UControlSymbol;
class ASolarBody;
class AActor;
class APlayController;
class AAstroPlanet;
class ADroneBase;

void AAstroCharacter::UpdatePlayerIndex() {
}

void AAstroCharacter::UpdateHeldItem_Implementation() {
}




void AAstroCharacter::SetSprinting(bool Sprint) {
}

void AAstroCharacter::SetPlayerIndex(uint8 Index) {
}

void AAstroCharacter::SetItemSpawnPreviewActive(bool bIsActive) {
}

void AAstroCharacter::SetHoverDown(bool hover) {
}

void AAstroCharacter::SetFreeOxygen(bool bNewFreeOxygen) {
}

void AAstroCharacter::SetBackpackChildActorComponent(UChildActorComponent* NewBackpackChildActorComponent) {
}

void AAstroCharacter::ServerSetMissionTracked_Implementation(const FName missionId, bool bTracked) {
}
bool AAstroCharacter::ServerSetMissionTracked_Validate(const FName missionId, bool bTracked) {
    return true;
}

void AAstroCharacter::ServerSetMissionSeen_Implementation(const FName missionId, bool bSeen) {
}
bool AAstroCharacter::ServerSetMissionSeen_Validate(const FName missionId, bool bSeen) {
    return true;
}

void AAstroCharacter::ServerSetCreativeDroneDeployed_Implementation(bool IsDeployed) {
}
bool AAstroCharacter::ServerSetCreativeDroneDeployed_Validate(bool IsDeployed) {
    return true;
}

void AAstroCharacter::ServerDropHeavyCarriedItems_Implementation() {
}
bool AAstroCharacter::ServerDropHeavyCarriedItems_Validate() {
    return true;
}

void AAstroCharacter::ReapplySavedCharacterCustomization() {
}



void AAstroCharacter::PointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector& Normal) {
}

void AAstroCharacter::PlayDamageSound_Implementation() {
}



void AAstroCharacter::OnRep_LocalSolarBody(ASolarBody* oldSolarBody) {
}

void AAstroCharacter::OnRep_IsPowered() {
}


void AAstroCharacter::OnRep_Health() {
}


void AAstroCharacter::OnRep_CharacterCustomization() {
}


void AAstroCharacter::OnImmunityInitiatorDestroyed(AActor* destroyedInitiator) {
}

void AAstroCharacter::OnGameplayStarted() {
}


void AAstroCharacter::NotifyPlayerDeathBegin() {
}

void AAstroCharacter::MulticastPointItem_Implementation(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector_NetQuantizeNormal& Normal) {
}

bool AAstroCharacter::MissionTracked(const FName missionId) const {
    return false;
}

bool AAstroCharacter::MissionSeen(const FName missionId) const {
    return false;
}

bool AAstroCharacter::IsCreativeDroneCameraPerspectiveActive() const {
    return false;
}

void AAstroCharacter::HandleOnGameplayStartedEvent(bool StartedInExistingSavedGame) {
}

bool AAstroCharacter::GetSprinting() {
    return false;
}

FTransform AAstroCharacter::GetSpawnPreviewTransform() {
    return FTransform{};
}

APlayController* AAstroCharacter::GetPlayController() {
    return NULL;
}

FString AAstroCharacter::GetOnlinePlayerName() {
    return TEXT("");
}

bool AAstroCharacter::GetOnHoverboard() const {
    return false;
}

ASolarBody* AAstroCharacter::GetLocalSolarBody() const {
    return NULL;
}

AAstroPlanet* AAstroCharacter::GetLocalPlanet() const {
    return NULL;
}

bool AAstroCharacter::GetHoverDown() {
    return false;
}


EDroneControlState AAstroCharacter::GetDroneControlState() const {
    return EDroneControlState::NotUsingDrone;
}


ADroneBase* AAstroCharacter::GetCreativeDrone() const {
    return NULL;
}

ABackpack* AAstroCharacter::GetBackpack() const {
    return NULL;
}

void AAstroCharacter::Focus(const FVector& Location, bool rotationOnly) {
}

void AAstroCharacter::EndFocus() {
}


void AAstroCharacter::DetachFromSeat(bool bImmediate, bool bForce) {
}



void AAstroCharacter::AuthoritySetOnHoverboard(bool bNewOnHoverboard) {
}

void AAstroCharacter::AuthoritySetLocalSolarBody(ASolarBody* SolarBody) {
}

void AAstroCharacter::AuthoritySetIsImmuneToDamage(bool bNewIsImmuneToDamage, AActor* immunityInitiator) {
}



void AAstroCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroCharacter, CurrentSpeed);
    DOREPLIFETIME(AAstroCharacter, CurrentVelocity);
    DOREPLIFETIME(AAstroCharacter, Jumped);
    DOREPLIFETIME(AAstroCharacter, ActuatorRerouteHelper);
    DOREPLIFETIME(AAstroCharacter, HeldItem);
    DOREPLIFETIME(AAstroCharacter, AccentMaterialIndex);
    DOREPLIFETIME(AAstroCharacter, ReplicatedVelocity);
    DOREPLIFETIME(AAstroCharacter, ReplicatedMovementMode);
    DOREPLIFETIME(AAstroCharacter, LocalSolarBody);
    DOREPLIFETIME(AAstroCharacter, MissionsSeen);
    DOREPLIFETIME(AAstroCharacter, MissionsTracked);
    DOREPLIFETIME(AAstroCharacter, bIsOxygenFilling);
    DOREPLIFETIME(AAstroCharacter, bIsTired);
    DOREPLIFETIME(AAstroCharacter, bHaveLifeSupport);
    DOREPLIFETIME(AAstroCharacter, bBreathing);
    DOREPLIFETIME(AAstroCharacter, bIsSuffocating);
    DOREPLIFETIME(AAstroCharacter, bIsAlive);
    DOREPLIFETIME(AAstroCharacter, bIsPowered);
    DOREPLIFETIME(AAstroCharacter, bIsLightsOn);
    DOREPLIFETIME(AAstroCharacter, bIsImmuneToDamage);
    DOREPLIFETIME(AAstroCharacter, bSimulationStarted);
    DOREPLIFETIME(AAstroCharacter, bFreeOxygen);
    DOREPLIFETIME(AAstroCharacter, bOnHoverboard);
    DOREPLIFETIME(AAstroCharacter, FatigueLevel);
    DOREPLIFETIME(AAstroCharacter, OxygenLevel);
    DOREPLIFETIME(AAstroCharacter, Health);
    DOREPLIFETIME(AAstroCharacter, DeathAnim);
    DOREPLIFETIME(AAstroCharacter, StormEncumbrance);
}

AAstroCharacter::AAstroCharacter() {
    this->MeshUsedAsIcon = NULL;
    this->FallDampening = 0.50f;
    this->CurrentSpeed = 0.00f;
    this->Driving = false;
    this->Dying = false;
    this->Walking = false;
    this->SwappingItem = false;
    this->DrivingActor = NULL;
    this->AttachOwner = NULL;
    this->Jumped = false;
    this->JumpInputReceived = false;
    this->Sprinting = false;
    this->HoldingIndicatorMesh = NULL;
    this->HoldingIndicatorMaterial = NULL;
    this->HoldingIndicatorDirMesh = NULL;
    this->HoldingIndicatorDirMaterial = NULL;
    this->ActuatorRerouteHelper = NULL;
    this->HoldingIndicatorMeshComponent = NULL;
    this->HoldingIndicatorDirMeshComponent = NULL;
    this->HeldItem = NULL;
    this->grabAnimSpeed = 1.50f;
    this->Focusing = false;
    this->FocusingRotation = false;
    this->bEnableHeadlook = true;
    this->HoldingTool = false;
    this->IsHeavyCarrying = false;
    this->BackpackRaised = false;
    this->AccentMaterialIndex = 255;
    this->LastGestureTime = 0.00f;
    this->AstroMovementComponent = NULL;
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
    this->MeshComponent = NULL;
    this->WindParticles = NULL;
    this->ItemSpawnPreviewLocation = NULL;
    this->ItemSpawnPreviewSlot = NULL;
    this->ReplicatedMovementMode = 0;
    this->FoliageSoundCollisionRadius = 0.00f;
    this->DisableLight = false;
    this->LocalSolarBody = NULL;
    this->backpackChildActorComponent = NULL;
    this->LastHeldItem = NULL;
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
    this->PointActionType = UAstroPlayMontageAction::StaticClass();
    this->AddBrushIndicator = NULL;
    this->SubtractBrushIndicator = NULL;
    this->FlattenBrushIndicator = NULL;
    this->ColorPickerIndicator = NULL;
    this->PaintBrushIndicator = NULL;
    this->BrushIndicatorMaterial = NULL;
    this->BrushIndicatorMID = NULL;
    this->BrushIndicatorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BrushIndicatorMesh"));
    this->bIsOxygenFilling = false;
    this->bIsTired = false;
    this->bHaveLifeSupport = false;
    this->bBreathing = false;
    this->bIsSuffocating = false;
    this->bIsAlive = true;
    this->bIsPowered = false;
    this->bIsLightsOn = true;
    this->bInvincible = true;
    this->bIsImmuneToDamage = false;
    this->bSimulationStarted = false;
    this->bFreeOxygen = false;
    this->bOnHoverboard = false;
    this->OxygenUseMultiplier = 1.00f;
    this->FatigueLevel = 1.00f;
    this->OxygenLevel = 0.00f;
    this->Health = 1.00f;
    this->MaxHealth = 1.00f;
    this->DeathAnim = 0;
    this->StormEncumbrance = 0.00f;
    this->LightIntensity = 0.00f;
    this->FilterBundleType = NULL;
    this->StoredOxygenType = NULL;
    this->OxygenType = NULL;
    this->SafeZoneRadius = 0.00f;
    this->RelativeBackpackUnbundleRayCastOrigins.AddDefaulted(2);
}

