// Fill out your copyright notice in the Description page of Project Settings.

#include "ClickableComponent.h"


// Sets default values for this component's properties
UClickableComponent::UClickableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UClickableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UClickableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


EUseContext UClickableComponent::GetActiveUseContext()
{
	return EUseContext::UC_Use;
}

void UClickableComponent::SetActiveUseContext(EUseContext NewUseContext)
{

}