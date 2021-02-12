// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/ActorComponent.h"
#include "ExplosiveComponent.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct ASTRO_API FExplosiveEffectsConfigPair
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MinPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* Effect;
};

UCLASS(BlueprintType, Blueprintable)
class ASTRO_API UExplosiveEffectsConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ExplosionAudioEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FExplosiveEffectsConfigPair> EffectByPowerLevel;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UExplosiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExplosiveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void Detonate();
	UFUNCTION(BlueprintCallable)
		void SetDetonationTimer(float DeltaTime);
	UFUNCTION(BlueprintCallable)
		void SetDetonationTimerPaused(bool bIsPaused);
	UFUNCTION(BlueprintCallable)
		void CancelDetonationTimer();
	UFUNCTION(BlueprintCallable)
		void DoExplosionDeformation(FVector location, float radius);
	UFUNCTION(BlueprintCallable)
		void DoBlastDamage(FVector location, float radius, float intensity);
	UFUNCTION(BlueprintCallable)
		void DamageActor(AActor* actor, FVector direction, float intensity);
	UFUNCTION(BlueprintCallable)
		bool ExplosiveDestroyActor(AActor* ToDestroy);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AutoResourceGenerationPercentage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CombineExplosionsRadiusRatio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ExplosionRadiusCraterScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PowerToRadiusScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UDamageType> DamageTypeClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UExplosiveEffectsConfig* EffectsConfig;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CombinedPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CombinedRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CombinedLocation;
};
