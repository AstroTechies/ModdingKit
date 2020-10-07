// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UPowerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPowerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Take a guess
		bool Enabled = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Should this machine generate power?
		bool bIsGenerator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// If this number is positive, it is the U/s that this machine will output. If this number is negative, it is the U/s that this machine will draw 
		float NetPowerOutput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Unsure, only rovers seem to use this field
		bool SelfDischargeOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Is this battery built into the chassis of a machine?
		bool IsIntegratedBattery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Does this machine need power to work?
		bool QueryPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The amount of power that this battery can hold in units
		float StorageCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The number of U/s that this battery can discharge
		float DischargeRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The number of U/s that this battery can charge
		float ChargeRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Unsure, needs testing
		float DiscreteDelta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsLoad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ShouldReplicate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentChargeRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float NetActualLoad;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentAvailablePower;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentMaximumLoad;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentCharge;

};
