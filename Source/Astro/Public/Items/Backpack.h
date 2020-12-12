// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ChildActorComponent.h"
#include "Backpack.generated.h"

class AAstroCharacter;

UCLASS(BlueprintType)
class ASTRO_API ABackpack : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void SetOpen(bool isOpen);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetOpen();
	UFUNCTION(BlueprintCallable)
		void ToggleOpen();
	UFUNCTION(BlueprintCallable)
		void SetCatalog(UChildActorComponent* catalog, UChildActorComponent* catalogCreative);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		AAstroCharacter* GetCharacter();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsLocallyControlled();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		AActor* GetChildCatalog();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		AActor* GetInactiveChildCatalog();
	UFUNCTION(BlueprintCallable)
		void AuthorityRemoveOxygenTankPropertiesOverride();
	UFUNCTION(BlueprintCallable)
		void OnCreativeModeEnabledChanged(bool bIsCreativeModeEnabled);
	UFUNCTION(BlueprintCallable)
		void AuthorityAttemptToSpawnCreativeDrone();
	UFUNCTION(BlueprintCallable)
		void OnLeftAuxPressed();
	UFUNCTION(BlueprintCallable)
		void OnLeftAuxReleased();
	UFUNCTION(BlueprintCallable)
		void OnRightAuxPressed();
	UFUNCTION(BlueprintCallable)
		void OnRightAuxReleased();
	UFUNCTION(BlueprintCallable)
		void OnCancel();
	UFUNCTION(BlueprintCallable)
		void OnDeformToolEquippedStateChanged(bool equipped);
	UFUNCTION(BlueprintCallable)
		void HandlePlayerDeathBegins();
	UFUNCTION(BlueprintCallable)
		void OnRep_Catalog();
	UFUNCTION(BlueprintCallable)
		void OnRep_CreativeDrone();
	UFUNCTION(BlueprintCallable)
		void HandleDroneFlightStateChanged();
};