// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SolarBody.h"
#include "AstroPlanet.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API AAstroPlanet : public ASolarBody
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	//AAstroPlanet();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	/*UFUNCTION(BlueprintCallable)
		bool CanBeVisitedByPlayer();

	UFUNCTION(BlueprintCallable)
		FVector GetOrbitAxis();

	UFUNCTION(BlueprintCallable)
		void SetBodyTransform(FTransform& Transform);

	UFUNCTION(BlueprintCallable)
		FTransform GetBodyTransform();

	UFUNCTION(BlueprintCallable)
		USceneComponent* GetProxyComponent();

	UFUNCTION(BlueprintCallable)
		USceneComponent* GetCenterComponent();

	UFUNCTION(BlueprintCallable)
		FRotator GetDayRotationOffset();

	UFUNCTION(BlueprintCallable)
		bool GeneratesGravitySource();

	UFUNCTION(BlueprintCallable)
		float GetNormalizedDayTime();

	UFUNCTION(BlueprintCallable)
		void SetNormalizedDayTime(float normalizedDayTime);

	UFUNCTION(BlueprintCallable)
		void SetDayLength(float newDayLength);

	UFUNCTION(BlueprintCallable)
		void SetOrbitAxisRotation(float rads);

	UFUNCTION(BlueprintCallable)
		float GetLastOrbitAxisRotation();

	UFUNCTION(BlueprintCallable)
		FVector GetCenter();

	UFUNCTION(BlueprintCallable)
		FVector GetProxyCenter();

	UFUNCTION(BlueprintCallable)
		FVector GetCenterRelativeOffset();

	UFUNCTION(BlueprintCallable)
		float GetRadius();

	UFUNCTION(BlueprintCallable)
		float GetMaxFlightRadius();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float WorldSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector GravityVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Gravity;*/
	
	UFUNCTION(BlueprintCallable)
		float GetRadius();

};
