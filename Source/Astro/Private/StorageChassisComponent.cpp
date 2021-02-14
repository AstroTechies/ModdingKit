// Fill out your copyright notice in the Description page of Project Settings.


#include "StorageChassisComponent.h"

// Sets default values for this component's properties
UStorageChassisComponent::UStorageChassisComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStorageChassisComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStorageChassisComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UStorageChassisComponent::QueryTertiary(APlayerController* Controller, FTransform OutTransform)
{
	return false;
}

void UStorageChassisComponent::TertiaryUse(APlayerController* Controller)
{

}

void UStorageChassisComponent::SlotEvent(APhysicalItem* item)
{

}

void UStorageChassisComponent::ItemAmountChangeEvent()
{

}

UStorageChassisComponent* UStorageChassisComponent::GetActorStorageChassisComponent(AActor* Actor)
{
	return nullptr;
}

int UStorageChassisComponent::ChangeDeformationDeltaInConnectedSlotNetwork(int sedimentAmount, TSubclassOf<UItemType> deformedItemType)
{
	return 0;
}

void UStorageChassisComponent::CalculateItemReservesInConnectedSlotNetwork(TSubclassOf<UItemType> ItemType, int outCurrentStoredItemAmount, int outMaxStorageSize)
{

}

bool UStorageChassisComponent::AuthorityPlaceItemInConnectedSlotNetwork(APhysicalItem* Item, AActor* SourceOwner)
{
	return false;
}

bool UStorageChassisComponent::AuthorityPlaceItemInLocalStorage(APhysicalItem* Item)
{
	return false;
}

int UStorageChassisComponent::AddItem(TSubclassOf<UItemType> itemType, int itemAmount)
{
	return 0;
}

UStorageChassisComponent* UStorageChassisComponent::GetOutermostStorage(AActor* Actor, bool Inclusive)
{
	return nullptr;
}

TArray<FSlotReference> UStorageChassisComponent::GetUnmanagedSlots()
{
	TArray<FSlotReference> x;
	return x;
}

USlotOrganizationRule* UStorageChassisComponent::FindRuleByName(FName ruleName)
{
	return nullptr;
}

void UStorageChassisComponent::AuthorityApplyOrganizationRules()
{

}

void UStorageChassisComponent::OnRep_SlotIndicatorLocations()
{

}

void UStorageChassisComponent::OnRep_ActorAttachments()
{

}

void UStorageChassisComponent::OnPlayerEnterExitAttachment(bool entered)
{

}

void UStorageChassisComponent::OnOwnerDestroyed(AActor* owner)
{

}