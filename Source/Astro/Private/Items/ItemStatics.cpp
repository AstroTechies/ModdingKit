// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemStatics.h"
#include "PhysicalItem.h"

APhysicalItem* UItemStatics::SpawnDeployablePackagedItem(UObject* WorldContextObject, TSubclassOf<APhysicalItem> PhysicalItemClassPackagedItemWillContain, FTransform SpawnTransform)
{
	return nullptr;
}

APhysicalItem* UItemStatics::PhysicalItemDefault(TSubclassOf<APhysicalItem> PhysicalItemClass)
{
	return nullptr;
}

int UItemStatics::AmountFromRecipe(float Count)
{
	return 0;
}

float UItemStatics::RecipeFromAmount(int Amount)
{
	return 0;
}