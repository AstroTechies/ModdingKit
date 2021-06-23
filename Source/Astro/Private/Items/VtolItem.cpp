// Fill out your copyright notice in the Description page of Project Settings.

#include "VtolItem.h"

AVtolItem::AVtolItem()
{
	MovementComponent = CreateDefaultSubobject<UFlyingVtolMovementComponent>(TEXT("FlyingVtolMovement"));
	FuelConsumerComponent = CreateDefaultSubobject<UFuelConsumerComponent>(TEXT("Fuel Consumer Component"));
}

void AVtolItem::RouteAux1ToggleUse(AAstroPlayerController* controller, EInputEvent eventType)
{

}

void AVtolItem::RouteAux2ToggleUse(AAstroPlayerController* controller, EInputEvent eventType)
{

}

ASolarBody* AVtolItem::GetLocalSolarBody()
{
	return nullptr;
}

void AVtolItem::SetRiseInputActive()
{

}

void AVtolItem::SetRiseInputInactive()
{

}

bool AVtolItem::IsLocallyControlled()
{
	return false;
}

void AVtolItem::HandleVehicleManned(AAstroPlayerController* NewPilot)
{

}

void AVtolItem::HandleVehicleUnmanned(AAstroPlayerController* OldPilot)
{

}

void AVtolItem::OnSlottedItemsChanged()
{

}

void AVtolItem::OnFuelRecipeAmountChanged(float amount)
{

}

void AVtolItem::OnCreativeModeFreeFuelChanged(bool bFreeFuel)
{

}

void AVtolItem::MulticastNotifyLandedChanged(bool bLanded)
{

}

void AVtolItem::TimeoutTooltipOverride()
{

}

void AVtolItem::UpdateWashEffectsState()
{

}