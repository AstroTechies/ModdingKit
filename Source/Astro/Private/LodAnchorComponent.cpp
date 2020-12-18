// Fill out your copyright notice in the Description page of Project Settings.

#include "LodAnchorComponent.h"


bool ULodAnchorComponent::UpdateInternal(FVector newPosition)
{
	return false;
}

void ULodAnchorComponent::ToggleActivated()
{

}

void ULodAnchorComponent::SetActivated(bool makeActive, bool forceUpdate)
{

}

void ULodAnchorComponent::ShowPreviz(bool show)
{

}

void ULodAnchorComponent::SetBeaconVisibility(bool enabled)
{

}

/*void ULodAnchorComponent::HandleDeformed(FDeformationParamsT2 params)
{

}*/

void ULodAnchorComponent::OnReplicated_IsAnchored()
{

}

void ULodAnchorComponent::ServerChangeActivated_Implementation(bool makeActive, bool forceUpdate)
{

}

bool ULodAnchorComponent::ServerChangeActivated_Validate(bool makeActive, bool forceUpdate)
{
	return true;
}