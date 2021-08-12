// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AstroPlayerController.h"
#include "PlayController.generated.h"

class AAstroCharacter;
class USceneComponent;
class UCameraComponent;
class ASolarBody;

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

	UFUNCTION(BlueprintCallable) void SetFreeCam();
	UFUNCTION(BlueprintCallable) FString RunScript(FString script);
	UFUNCTION(BlueprintCallable) void Ping();
	UFUNCTION(BlueprintCallable) void SetCurrentSpawnPoint(AActor* spawn);
	UFUNCTION(BlueprintCallable, BlueprintPure) AAstroCharacter* GetAstroCharacter();
	UFUNCTION(BlueprintCallable, BlueprintPure) USceneComponent* GetSpawnLocation();
	UFUNCTION(BlueprintCallable, BlueprintPure) UCameraComponent* GetCamera();
	UFUNCTION(BlueprintCallable, BlueprintPure) FRotator GetCameraRotation();
	UFUNCTION(BlueprintCallable, BlueprintPure) FVector GetCameraLocation();
	UFUNCTION(BlueprintCallable) void OnCharacterLocalSolarBodyChanged(ASolarBody* newLocalSolarBody);
	UFUNCTION(BlueprintCallable) void TeleportToCursor();

	UFUNCTION() // BlueprintCallable, BlueprintPure
		UTooltipManager* GetTooltipManager();
};
