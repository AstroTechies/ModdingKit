// Fill out your copyright notice in the Description page of Project Settings.


#include "PrinterComponent.h"

// Sets default values for this component's properties
UPrinterComponent::UPrinterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPrinterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPrinterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UPrinterComponent::CanReserveSlotsAcceptItemForActiveRecipe(APhysicalItem* Item)
{
	return false;
}

void UPrinterComponent::SetCanUse(bool bCanUse)
{

}

void UPrinterComponent::OnAuthorityControlPanelCrackedChanged(AControlPanel* controlPanel)
{

}

TSubclassOf<APhysicalItem> UPrinterComponent::GetCurrentItem()
{
	return APhysicalItem::StaticClass();
}

bool UPrinterComponent::GetCharging()
{
	return false;
}

bool UPrinterComponent::GetPrinting()
{
	return false;
}

bool UPrinterComponent::GetCanUse()
{
	return false;
}

bool UPrinterComponent::GetCanPrint()
{
	return false;
}

bool UPrinterComponent::GetItemIndicatorVisible()
{
	return false;
}

bool UPrinterComponent::GetItemIndicatorHidden()
{
	return false;
}

TArray<TSubclassOf<UItemType>> UPrinterComponent::GetSlotIndicators()
{
	TArray<TSubclassOf<UItemType>> x;
	return x;
}

TArray<int> UPrinterComponent::GetAvailableIngredientCounts()
{
	TArray<int> x;
	return x;
}

int UPrinterComponent::GetTotalAvailableBlueprintCount()
{
	return 0;
}

int UPrinterComponent::GetCurrentUnlockedBlueprintIndex()
{
	return 0;
}

bool UPrinterComponent::UpdatePreprinting()
{
	return false;
}

void UPrinterComponent::UpdatePrinting(float deltaTime)
{

}

void UPrinterComponent::SetLocalIsVisible(bool isVisible)
{

}

void UPrinterComponent::SetRepackageModeEnabled(bool modeEnabled)
{

}

void UPrinterComponent::SetItemsAvailableToRepackage(TArray<APhysicalItem*> itemsToRepackage, int DefaultSelectionIndex)
{

}

void UPrinterComponent::AddIgnoredActorForPrintAreaValidation(AActor* ignoredActor)
{

}

void UPrinterComponent::RemoveIgnoredActorForPrintAreaValidation(AActor* ignoredActor)
{

}

void UPrinterComponent::FinishPrinting()
{

}

void UPrinterComponent::CancelPrint()
{

}

void UPrinterComponent::StartPrinting()
{

}

void UPrinterComponent::IncrementBlueprint(bool doServerIncrement)
{

}

void UPrinterComponent::DecrementBlueprint(bool doServerIncrement)
{

}

void UPrinterComponent::ActivateBlueprint()
{

}

void UPrinterComponent::DeactivateBlueprint()
{

}

void UPrinterComponent::HideBlueprint()
{

}

void UPrinterComponent::CreateIndicatorFromClass(TSubclassOf<APhysicalItem> Class)
{

}

void UPrinterComponent::CreateIndicatorFromItem(APhysicalItem* Owner)
{

}

APhysicalItem* UPrinterComponent::SpawnPrintedItem()
{
	return nullptr;
}

void UPrinterComponent::ResetIndicator()
{

}

void UPrinterComponent::SetBlueprints(TArray<TSubclassOf<APhysicalItem>> newBlueprints)
{

}

void UPrinterComponent::SetPrinterOutputSlot(FSlotReference slot)
{

}

void UPrinterComponent::ShowNeededIndicators()
{

}

void UPrinterComponent::HideNeededIndicators()
{

}

void UPrinterComponent::SetText(FText Text)
{

}

FTransform UPrinterComponent::GetPrintingTransform()
{
	return FTransform();
}

float UPrinterComponent::GetPrintingHeight()
{
	return 0;
}

bool UPrinterComponent::PrinterClickQuery(UClickQuery* Query)
{
	return false;
}

void UPrinterComponent::SetPrintSpeed(float speed)
{

}

void UPrinterComponent::SetRequiresPower(bool printerRequiresPower)
{

}

bool UPrinterComponent::GetRepackageModeEngaged()
{
	return false;
}

UPrinterComponent* UPrinterComponent::ActorPrinterComponent(AActor* Actor)
{
	return nullptr;
}

void UPrinterComponent::UnlockedItemsChanged(TArray<TSubclassOf<UItemType>> newUnlockedItems)
{

}

void UPrinterComponent::OnPrinterDestroyed(AActor* destroyedActor)
{

}

void UPrinterComponent::HandleCreativeCatalogUnlockedChanged()
{

}

bool UPrinterComponent::GetHasAllIngredients()
{
	return false;
}

void UPrinterComponent::OnRep_CurrentBlueprintItem()
{

}

void UPrinterComponent::OnRep_PrinterOutputSlot()
{

}

void UPrinterComponent::OnRep_PrintState()
{

}

void UPrinterComponent::OnRep_SlotIndicators()
{

}

void UPrinterComponent::OnRep_Progress()
{

}

void UPrinterComponent::OnRep_PrinterStateAtomic()
{

}