// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicalResource.h"

bool APhysicalResource::IsFull()
{
	return false;
}

bool APhysicalResource::IsEmpty()
{
	return true;
}

float APhysicalResource::GetFullness()
{
	return 0;
}

void APhysicalResource::SetView_Implementation()
{

}

void APhysicalResource::OnDrained_Implementation()
{

}