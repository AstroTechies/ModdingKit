// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhysicalItem.h"
#include "ItemStatics.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UItemStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static APhysicalItem* SpawnDeployablePackagedItem(UObject* WorldContextObject, TSubclassOf<APhysicalItem> PhysicalItemClassPackagedItemWillContain, FTransform SpawnTransform);
	UFUNCTION(BlueprintCallable)
		static APhysicalItem* PhysicalItemDefault(TSubclassOf<APhysicalItem> PhysicalItemClass);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int AmountFromRecipe(float Count);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float RecipeFromAmount(int Amount);
};
