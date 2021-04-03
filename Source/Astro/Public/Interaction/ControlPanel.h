// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "GameFramework/Actor.h"
#include "ControlPanel.generated.h"

class USkeletalMeshComponent;
class USpotLightComponent;
class UClickableComponent;
class UCrackableActorComponent;

UENUM()
enum class EControlPanelNavigationDirection : uint8 {
	Left = 0,
	Right = 1,
	Up = 2,
	Down = 3
};

UCLASS()
class ASTRO_API AControlPanel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlPanel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnOwnerChanged;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		USpotLightComponent* ControlPanelLight;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UCrackableActorComponent* CrackableActorComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UClickableComponent* ClickableComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* ControlledActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FName, EControlPanelNavigationDirection> NavigationComponentMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FirstNavigationRepeatDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float NavigationRepetitionInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AnalogStickNavigationThreshold;
};
