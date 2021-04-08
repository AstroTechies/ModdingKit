// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "Components/ActorComponent.h"
#include "TerrainPhysicsComponent.generated.h"

class UPrimitiveComponent;

UCLASS(EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UTerrainPhysicsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTerrainPhysicsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable) void SetWorldPhysics();
	UFUNCTION(BlueprintCallable) void SetBuryPhysics();
	UFUNCTION(BlueprintCallable) void SetPickupPhysics();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetIsBuried();
	UFUNCTION(BlueprintCallable) void SetIsBuried(bool NewIsBuried);
	UFUNCTION(BlueprintCallable, BlueprintPure) bool IsTerrainBuried();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FSignal OnSetBuryPhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FSignal OnSetWorldPhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FIsBuriedChangedEvent OnIsBuriedChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName OverrideWorldPhysicsProfile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName OverrideBuryPhysicsProfile;

};
