#include "Backpack.h"
#include "Net/UnrealNetwork.h"

class AActor;
class AAstroCharacter;
class APhysicalItem;
class UChildActorComponent;
class UCrackableActorComponent;

void ABackpack::ToggleOpen() {
}

void ABackpack::SetOpen(bool IsOpen) {
}

void ABackpack::SetMissionLog(UChildActorComponent* missionLog) {
}

void ABackpack::SetCatalog(UChildActorComponent* Catalog, UChildActorComponent* catalogCreative) {
}

void ABackpack::OnRightAuxReleased() {
}

void ABackpack::OnRightAuxPressed() {
}

void ABackpack::OnRep_MissionLog() {
}

void ABackpack::OnRep_CreativeDrone() {
}

void ABackpack::OnRep_Catalog() {
}


void ABackpack::OnLeftAuxReleased() {
}

void ABackpack::OnLeftAuxPressed() {
}

void ABackpack::OnItemInSlotChanged(APhysicalItem* Item) {
}

void ABackpack::OnDeformToolEquippedStateChanged(bool equipped) {
}

void ABackpack::OnCreativeModeEnabledChanged(bool bIsCreativeModeEnabled) {
}

void ABackpack::OnCancel() {
}

void ABackpack::OnBackpackAttachedDisplayCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool cracked) {
}

bool ABackpack::IsLocallyControlled() {
    return false;
}

void ABackpack::HandlePlayerDeathBegins() {
}

void ABackpack::HandleDroneFlightStateChanged() {
}

bool ABackpack::GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, FVector& OutUnbundleOrigin) {
    return false;
}

FBackpackOxygenTankProperties ABackpack::GetOxygenTankProperties() const {
    return FBackpackOxygenTankProperties{};
}

bool ABackpack::GetOpen() {
    return false;
}

AActor* ABackpack::GetInactiveChildCatalog() {
    return NULL;
}

AActor* ABackpack::GetChildMissionLog() {
    return NULL;
}

AActor* ABackpack::GetChildCatalog() {
    return NULL;
}

AAstroCharacter* ABackpack::GetCharacter() {
    return NULL;
}

void ABackpack::AuthorityRemoveOxygenTankPropertiesOverride() {
}

void ABackpack::AuthorityAttemptToSpawnCreativeDrone() {
}

void ABackpack::AuthorityApplyOxygenTankPropertiesOverride(const FBackpackOxygenTankProperties& OverrideProperties) {
}

void ABackpack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABackpack, CreativeDrone);
    DOREPLIFETIME(ABackpack, AttachedLights);
    DOREPLIFETIME(ABackpack, CatalogActor);
    DOREPLIFETIME(ABackpack, MissionLogActor);
    DOREPLIFETIME(ABackpack, CatalogCreativeActor);
    DOREPLIFETIME(ABackpack, OxygenTankPropertiesOverride);
}

ABackpack::ABackpack() {
    this->CreativeDrone = NULL;
    this->CreativeDroneClass = NULL;
    this->VirtualLightComponent = NULL;
    this->PendingDronePaletteMaterial = NULL;
    this->CatalogCrackable = NULL;
    this->CatalogCrackableCreative = NULL;
    this->MissionLogCrackable = NULL;
    this->CachedDeformTool = NULL;
    this->CatalogActor = NULL;
    this->MissionLogActor = NULL;
    this->CatalogActorPrev = NULL;
    this->CatalogCreativeActor = NULL;
    this->CatalogCreativeActorPrev = NULL;
}

