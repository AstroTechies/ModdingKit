// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LodAnchorState.h"
#include "LodAnchorComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API ULodAnchorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		bool UpdateInternal(FVector newPosition);
	UFUNCTION(BlueprintCallable)
		void ToggleActivated();
	UFUNCTION(BlueprintCallable)
		void SetActivated(bool makeActive, bool forceUpdate);
	UFUNCTION(BlueprintCallable)
		void ShowPreviz(bool show);
	UFUNCTION(BlueprintCallable)
		void SetBeaconVisibility(bool enabled);
	/*UFUNCTION(BlueprintCallable)
		void HandleDeformed(FDeformationParamsT2 params);*/
	UFUNCTION(BlueprintCallable)
		void OnReplicated_IsAnchored();
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerChangeActivated(bool makeActive, bool forceUpdate);

	UPROPERTY(EditAnywhere)
		FComponentReference BeaconReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ELodAnchorState IsAnchored;
};