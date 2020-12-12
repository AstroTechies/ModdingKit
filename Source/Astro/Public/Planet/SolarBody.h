// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SolarBody.generated.h"

UCLASS()
class ASTRO_API ASolarBody : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASolarBody();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector GravityVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GravityCylinderHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GravityRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Gravity;

	UFUNCTION(BlueprintCallable, BlueprintPure)
		struct FVector GetCenter();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		struct FVector GetProxyCenter();
};
