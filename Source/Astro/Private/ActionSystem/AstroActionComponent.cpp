// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroActionComponent.h"

UAstroAction* UAstroActionComponent::CreateAction(TSubclassOf<UAstroAction> ActionType)
{
	return nullptr;
}

bool UAstroActionComponent::StartAction(TSubclassOf<UAstroAction> ActionType)
{
	return false;
}

bool UAstroActionComponent::StartActionInstance(UAstroAction* action, EAstroActionNetworking Networking)
{
	return false;
}