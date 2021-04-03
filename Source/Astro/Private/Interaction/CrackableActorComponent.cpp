// Fill out your copyright notice in the Description page of Project Settings.


#include "CrackableActorComponent.h"

// Sets default values for this component's properties
UCrackableActorComponent::UCrackableActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCrackableActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCrackableActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCrackableActorComponent::SetCracked(bool NewCracked)
{

}

bool UCrackableActorComponent::GetCracked()
{
	return false;
}

bool UCrackableActorComponent::GetFullyClosed()
{
	return false;
}

bool UCrackableActorComponent::GetFullyOpen()
{
	return false;
}

bool UCrackableActorComponent::CanClickToClose()
{
	return false;
}

FTransform UCrackableActorComponent::GetClosedRelativeTransform()
{
	return FTransform();
}

void UCrackableActorComponent::SetClosedRelativeTransform(FTransform ClosedRelativeTransform)
{

}

bool UCrackableActorComponent::IsExaminable()
{
	return false;
}

bool UCrackableActorComponent::CracksOnlyOnExamine()
{
	return false;
}

void UCrackableActorComponent::OnParentCrackedChanged(UCrackableActorComponent* parentCrackableActorComponent, bool bParentCracked)
{

}

void UCrackableActorComponent::OnRep_Cracked()
{

}

void UCrackableActorComponent::OnClickUnhandled()
{

}

void UCrackableActorComponent::OnRep_StartingRelativeTransform()
{

}