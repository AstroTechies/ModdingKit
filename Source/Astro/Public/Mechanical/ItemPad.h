// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "Components/SceneComponent.h"
#include "ItemPadActor.h"
#include "ItemPad.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UItemPad : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemPad();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AutoSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ManuallyReplicatePadTransform = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AItemPadActor> PadClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnSpawnPad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnDestroyPad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AItemPadActor* Pad;
};
