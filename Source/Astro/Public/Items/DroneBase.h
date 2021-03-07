
#pragma once

#include "Planet/AstroPlanet.h"
#include "GameFramework/PlayerController.h"
#include "DroneBase.generated.h"

UCLASS(BlueprintType)
class ASTRO_API ADroneBase : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AuthorityLaunchDrone(APlayController* owningController);
	
	UFUNCTION(BlueprintCallable)
	void AuthorityEmergencyRecallDrone();
	
	UFUNCTION(BlueprintCallable)
	void AuthorityRecallDrone();
	
	UFUNCTION(BlueprintCallable)
	ASolarBody* GetLocalSolarBody();
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentFOV();
	
	UFUNCTION(BlueprintCallable)
	void SetRiseInputActive();
	
	UFUNCTION(BlueprintCallable)
	void SetRiseInputInactive();
	
	UFUNCTION(BlueprintCallable)
	void ZoomIn();
	
	UFUNCTION(BlueprintCallable)
	void ZoomOut();
	
	UFUNCTION(BlueprintCallable)
	void HandlePlacedInSlot();
	
	UFUNCTION(BlueprintCallable)
	void HandlePlayerReachedSpaceInShuttle();
	
	UFUNCTION(BlueprintCallable)
	void NudgeFlightSpeedSlower();
	
	UFUNCTION(BlueprintCallable)
	void NudgeFlightSpeedFaster();
	
	UFUNCTION(BlueprintCallable)
	void OnRep_FlightState();
	
	UFUNCTION(BlueprintCallable,BlueprintPure)
	bool IsLocallyControlled();
};