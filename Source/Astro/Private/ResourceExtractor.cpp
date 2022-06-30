#include "ResourceExtractor.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "AstroActionComponent.h"
#include "PowerComponent.h"
#include "ResourceCacheComponent.h"
#include "StorageChassisComponent.h"

class APhysicalItem;
class UItemType;
class UStaticMesh;
class UAstroAction;
class UPrimitiveComponent;

void AResourceExtractor::OnStorageChassisSlotEventSignal(APhysicalItem* Item) {
}

void AResourceExtractor::OnSingleAnimCustomNotifyEvent(FName NotifyName) {
}

void AResourceExtractor::OnResourceSlotFull(TSubclassOf<UItemType> Type) {
}

void AResourceExtractor::OnResourceItemReleased(APhysicalItem* Item) {
}

void AResourceExtractor::OnRep_Stages() {
}

void AResourceExtractor::OnRep_NodesInArea() {
}

void AResourceExtractor::OnRep_AnimProgress() {
}

void AResourceExtractor::OnRep_ActivationState() {
}

void AResourceExtractor::OnMontageEnded(UAstroAction* Action) {
}

void AResourceExtractor::OnHasPowerAvailableChanged(bool HasAvailablePower) {
}

void AResourceExtractor::MulticastGenerateFlecks_Implementation(UStaticMesh* StaticMesh, const FVector Location, const float Recipe) {
}

void AResourceExtractor::HandleOnPickedUpFromWorld(bool PhysicalMovement) {
}

void AResourceExtractor::HandleOnDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal, bool bIsTerrainComponent) {
}

void AResourceExtractor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AResourceExtractor, NodesInArea);
    DOREPLIFETIME(AResourceExtractor, AnimProgress);
    DOREPLIFETIME(AResourceExtractor, PowerRatio);
    DOREPLIFETIME(AResourceExtractor, AnimStage);
    DOREPLIFETIME(AResourceExtractor, OpStage);
    DOREPLIFETIME(AResourceExtractor, bIsTurnedOn);
}

AResourceExtractor::AResourceExtractor() {
    this->ManagerIndex = 4294967295;
    this->HammerDroppedHeight = 218.00f;
    this->HammerTopHeight = 459.00f;
    this->Radius = 1500.00f;
    this->PostPoundHoldTime = 1.00f;
    this->CycleTime = 10.00f;
    this->MaxLowPowerCycleTime = 0.00f;
    this->ResetTime = 1.00f;
    this->NuggetsPerNode = 2.00f;
    this->ThumpsPerNugget = 6;
    this->FullMeterThreshold = 150;
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
    this->VacuumLocationComponent = NULL;
    this->NodesInArea = 0;
    this->ResourceCache = CreateDefaultSubobject<UResourceCacheComponent>(TEXT("ResourceCache"));
    this->SkeletalMesh = NULL;
    this->StorageChassis = CreateDefaultSubobject<UStorageChassisComponent>(TEXT("StorageChassis"));
    this->ActivateAnimation = NULL;
    this->DeactivateAnimation = NULL;
    this->HammerDropMontage = NULL;
    this->FillBarMaterial = NULL;
    this->AnimProgress = 0.00f;
    this->PowerRatio = 0.00f;
    this->AnimStage = EExtractorAnimStage::Holding;
    this->OpStage = EExtractorOperationStage::Paused;
    this->bIsTurnedOn = false;
}

