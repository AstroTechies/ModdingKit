// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SolarBody.h"
#include "AstroPlayerController.h"
#include "PlayController.generated.h"

UCLASS()
class ASTRO_API APlayController : public AAstroPlayerController
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void OnCharacterLocalSolarBodyChanged(ASolarBody* newLocalSolarBody);
	
	UFUNCTION() // BlueprintCallable, BlueprintPure
		UTooltipManager* GetTooltipManager();

	UFUNCTION(BlueprintCallable)
		void TeleportToCursor();
};
