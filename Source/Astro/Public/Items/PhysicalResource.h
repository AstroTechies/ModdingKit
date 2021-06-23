// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PhysicalItem.h"
#include "PhysicalResource.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API APhysicalResource : public APhysicalItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure) bool IsFull();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool IsEmpty();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetFullness();

	UFUNCTION(BlueprintNativeEvent) void SetView();
	UFUNCTION(BlueprintNativeEvent) void OnDrained();
};
