// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehicleBase.h"
#include "GameFramework/Actor.h"
#include "SeatBase.generated.h"

UCLASS()
class ASTRO_API ASeatBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASeatBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		AVehicleBase* GetVehicleSlottedTo();
	
};
