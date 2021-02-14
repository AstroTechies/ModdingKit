// Fill out your copyright notice in the Description page of Project Settings.

#include "SlotsComponent.h"

// Sets default values for this component's properties
USlotsComponent::USlotsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USlotsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USlotsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FSlotReference USlotsComponent::MakeReference(FName SlotName)
{
	return FSlotReference();
}

bool USlotsComponent::SlotValid(FSlotReference Slot)
{
	return false;
}

bool USlotsComponent::SlotValidSlow(FSlotReference Slot)
{
	return false;
}

void USlotsComponent::SetSlotRelativeTransform(FSlotReference Slot, FTransform transform)
{

}

void USlotsComponent::SetSlotAcceptsItems(FSlotReference A, bool bAcceptsItems)
{

}

void USlotsComponent::SetSlotClickable(FSlotReference A, bool Clickable)
{

}

void USlotsComponent::SetSlotHidden(FSlotReference slotRef, bool bIsHidden)
{

}

void USlotsComponent::ConnectPowerToItem(FSlotReference slotRef, APhysicalItem* item)
{

}

ASlotConnection* USlotsComponent::MakeConnection(FSlotReference a, FSlotReference b, TSubclassOf<ASlotConnection> OverrideType, bool Visible)
{
	return nullptr;
}

ASlotConnection* USlotsComponent::MakeExclusiveConnection(FSlotReference a, FSlotReference b, TSubclassOf<ASlotConnection> OverrideType)
{
	return nullptr;
}

void USlotsComponent::BreakAllSlotConnections(FSlotReference Slot)
{

}

APhysicalItem* USlotsComponent::SpawnActorInSlot(FSlotReference Slot, TSubclassOf<APhysicalItem> Class)
{
	return nullptr;
}

bool USlotsComponent::SpawnItemTypeInSlot(FSlotReference Slot, TSubclassOf<UItemType> Type, bool StartFull)
{
	return false;
}

bool USlotsComponent::SpawnItemTypeInSlotWithDefaultContainer(FSlotReference Slot, TSubclassOf<UItemType> Type, TSubclassOf<UItemType> DefaultContainerType, bool StartFull)
{
	return false;
}

void USlotsComponent::DestroySlotItem(FSlotReference Slot)
{

}

void USlotsComponent::ReleaseItem(APhysicalItem* item, bool newOwner, bool FromTool, float RandomForce)
{

}

void USlotsComponent::ReleaseItem(FSlotReference Slot, APhysicalItem* item, bool newOwner, bool FromTool, float RandomForce)
{

}

void USlotsComponent::ReleaseItemWithEjectionImpulse(APhysicalItem* item, bool newOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset)
{

}

void USlotsComponent::ReleaseItemWithEjectionImpulse(FSlotReference Slot, APhysicalItem* item, bool newOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset)
{

}

void USlotsComponent::ReleaseSlotItemForce(FSlotReference Slot, float RandomForce)
{

}

void USlotsComponent::EmplaceSlotItem(FSlotReference Slot, APhysicalItem* item, bool snapTo, bool weld)
{

}

bool USlotsComponent::TakeSlotItemFromOther(FSlotReference Slot, FSlotReference Other)
{
	return false;
}

bool USlotsComponent::TakeSlotItemOfTypeFromOther(FSlotReference Slot, FSlotReference Other, TSubclassOf<UItemType> type)
{
	return false;
}

int USlotsComponent::SlotGetNumIndicators(FSlotReference Slot)
{
	return 0;
}

bool USlotsComponent::SlotAddIndicatorItem(FSlotReference Slot, TSubclassOf<APhysicalItem> type)
{
	return false;
}

bool USlotsComponent::SlotAddIndicatorItemType(FSlotReference Slot, TSubclassOf<UItemType> itemType)
{
	return false;
}

bool USlotsComponent::SlotAddIndicatorItemAttemptPackage(FSlotReference Slot, TSubclassOf<APhysicalItem> type)
{
	return false;
}

bool USlotsComponent::SlotAddIndicatorItemTypeAttemptPackage(FSlotReference Slot, TSubclassOf<UItemType> itemType)
{
	return false;
}

int USlotsComponent::SlotAttemptToPushIndicatorIntoSpecificSubslot(FSlotReference Slot, int SubslotIndex, FSlotIndicatorDefinition IndicatorDefinition)
{
	return 0;
}

int USlotsComponent::SlotPushIndicatorItemTypes(FSlotReference Slot, int Count, TArray<int> OutSubslotIndices, FSlotIndicatorDefinition IndicatorDefinition)
{
	return 0;
}

void USlotsComponent::SlotDestroyIndicators(FSlotReference Slot)
{

}

void USlotsComponent::SlotEnable(FSlotReference slotRef, bool Enable)
{

}

void USlotsComponent::SetSlotBreakable(FSlotReference slotRef, bool Breakable)
{

}

ESlotType USlotsComponent::GetSlotType(FSlotReference Slot)
{
	return ESlotType::Power;
}

void USlotsComponent::SetSlotAcceptsUnslottableItems(FSlotReference SlotRef, bool bAcceptsUnslottableItems)
{

}

bool USlotsComponent::SlotAcceptsItem(FSlotReference Slot, APhysicalItem* Item)
{
	return false;
}

bool USlotsComponent::SlotAcceptsItemTypeWithChangeInAmount(FSlotReference Slot, TSubclassOf<UItemType> itemType, bool isChangePositive)
{
	return false;
}

bool USlotsComponent::SlotAttemptToChangeItemAmountNormalized(FSlotReference Slot, TSubclassOf<UItemType> itemType, float normalizedAmount)
{
	return false;
}

bool USlotsComponent::SlotIsTrailerHitch(FSlotReference Slot)
{
	return false;
}

bool USlotsComponent::SlotPowerIncomingOnly(FSlotReference Slot)
{
	return false;
}

int USlotsComponent::SlotGetTier(FSlotReference Slot)
{
	return 0;
}

USlotsComponent* USlotsComponent::GetSlotOwner(FSlotReference Slot)
{
	return nullptr;
}

TArray<UStaticMeshComponent *> USlotsComponent::GetSlotLegacyMeshes(FSlotReference Slot)
{
	TArray<UStaticMeshComponent *> x;
	return x;
}

bool USlotsComponent::GetSlotTransform(FName slotName, FTransform outTransform)
{
	return false;
}

FTransform USlotsComponent::GetSlotTransform(FSlotReference Slot)
{
	return FTransform();
}

FTransform USlotsComponent::GetSlotRelativeTransform(FSlotReference Slot)
{
	return FTransform();
}

APhysicalItem* USlotsComponent::GetSlotPrimaryItem(FSlotReference Slot)
{
	return nullptr;
}

APhysicalItem* USlotsComponent::GetSlotItem(FSlotReference Slot, int SubslotIndex)
{
	return nullptr;
}

TArray<APhysicalItem *> USlotsComponent::GetSlotItems(FSlotReference Slot)
{
	TArray<APhysicalItem *> x;
	return x;
}

FSlotReference USlotsComponent::GetSlotConnectedSlot(FSlotReference Slot)
{
	return FSlotReference();
}

ESlotConfiguration USlotsComponent::GetSlotOrientationConfiguration(FSlotReference Slot)
{
	return ESlotConfiguration::Vertical;
}

ESlotConnectorType USlotsComponent::GetSlotConnectorType(FSlotReference Slot)
{
	return ESlotConnectorType::Plug;
}

bool USlotsComponent::SlotsEqual(FSlotReference A, FSlotReference B)
{
	return false;
}

/*USlotDelegates* USlotsComponent::GetSlotDelegates(FSlotReference Slot)
{
	return nullptr;
}*/

TArray<ASlotConnection *> USlotsComponent::GetSlotExternalConnections(FSlotReference Slot)
{
	TArray<ASlotConnection *> x;
	return x;
}

void USlotsComponent::OnSlotItemDestroyed(AActor* actor)
{

}

void USlotsComponent::OnRep_SlotTransitions()
{

}

void USlotsComponent::OnSlotIndicatorClicked(FSlotReference Slot, TSubclassOf<UItemType> Type)
{

}

void USlotsComponent::SetTracePrimitivesAsleep(bool bAreAsleep)
{

}

void USlotsComponent::AuxUse(FSlotReference auxSlot, AAstroPlayerController* controller, EInputEvent inputEvent)
{

}

void USlotsComponent::AuxUseAll(AAstroPlayerController* controller, EInputEvent inputEvent)
{

}

void USlotsComponent::AuxUseLeft(AAstroPlayerController* controller, EInputEvent inputEvent)
{

}

void USlotsComponent::AuxUseRight(AAstroPlayerController* controller, EInputEvent inputEvent)
{

}

void USlotsComponent::MulticastCancelSlotBehaviorTerrainInterpolation()
{

}

void USlotsComponent::OnRep_SlotRuleStatus()
{

}

void USlotsComponent::OnRep_SlotClickability()
{

}

void USlotsComponent::OnRep_SlotsAcceptItems()
{

}