// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slots/SlotReference.h"
#include "Components/ActorComponent.h"
#include "SlotResourceBehaviorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API USlotResourceBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlotResourceBehaviorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EjectWhenFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float EjectForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference EjectReceiver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString EjectAudioEvent;
};
