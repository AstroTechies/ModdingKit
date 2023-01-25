#include "SnailItem.h"
#include "AdaptiveTickComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlanetEffect.h"
#include "Templates/SubclassOf.h"

class AActor;
class APhysicalItem;
class UCrackableActorComponent;
class UItemList;
class UItemType;
class UPrimitiveComponent;





void ASnailItem::OnSnailCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool cracked) {
}

void ASnailItem::OnRep_OnSnailIsInteractableChanged() {
}


void ASnailItem::OnEffectRelevanceChanged(bool IsInRelevancy) {
}

void ASnailItem::OnChildActorInputActionUse() {
}

void ASnailItem::MulticastTriggerSnailBehavior_Implementation(ESnailBehaviorTriggerType Trigger, bool bLooping) {
}

void ASnailItem::MulticastSnailFedUpdate_Implementation(bool bNewFedState, ESnailFoodType newFoodType) {
}

bool ASnailItem::IsFed() {
    return false;
}

void ASnailItem::HandleRemovedFromSlot(bool NewOwner) {
}

void ASnailItem::HandlePlacedInSlot() {
}

void ASnailItem::HandlePickedUpInWorld(bool bPhysicalMovement) {
}

void ASnailItem::HandleOnSpawnedInSlot() {
}

void ASnailItem::HandleOnSetItemInFoodSlot(APhysicalItem* Item) {
}

void ASnailItem::HandleDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void ASnailItem::HandleChildActorClicked(AActor* Actor, FKey Key) {
}

TSubclassOf<UItemList> ASnailItem::GetValidFoodItemsFromFoodType(ESnailFoodType foodType) {
    return NULL;
}

ESnailFoodType ASnailItem::GetFoodTypeFromItemType(const TSubclassOf<UItemType> foodItemType) {
    return ESnailFoodType::InvalidFood;
}

float ASnailItem::GetElapsedBuffTime() {
    return 0.0f;
}

void ASnailItem::ChangeChildNetworkingPolicy(ECrackableActorNetworkingPolicy newPolicy) {
}

void ASnailItem::AuthoritySetSnailInteractable(bool bIsInteractable) {
}

void ASnailItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASnailItem, bSnailIsInteractable);
    DOREPLIFETIME(ASnailItem, bIsFed);
    DOREPLIFETIME(ASnailItem, remainingBuffTime);
}

ASnailItem::ASnailItem() {
    this->FedDuration = 600.00f;
    this->CurrentFoodType = ESnailFoodType::InvalidFood;
    this->AdjustedFedDuration = 0.00f;
    this->ChildActorComponent = NULL;
    this->ChildCrackableComponent = NULL;
    this->ChildSnailSkeleton = NULL;
    this->ChildTerrariumMesh = NULL;
    this->RootTerrariumMesh = NULL;
    this->ChildSlotComponent = NULL;
    this->TerrariumChildActor = NULL;
    this->bSnailIsInteractable = true;
    this->PlanetEffect = CreateDefaultSubobject<UPlanetEffect>(TEXT("Planet Effect"));
    this->AdaptiveTickComponent = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("AdaptiveTickComponent"));
    this->BehaviorTable = NULL;
    this->bIsFed = false;
    this->remainingBuffTime = 0.00f;
}

