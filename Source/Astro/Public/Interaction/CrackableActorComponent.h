// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "Components/ActorComponent.h"
#include "CrackableActorComponent.generated.h"

UENUM()
enum class ECrackableActorMethod : uint8 {
	Hover = 0,
	HoverFaceCamera = 1,
	Pivot = 2,
	None = 3
};

UENUM()
enum class ECrackableActorNetworkingPolicy : uint8 {
	LocalOnlyNoNetworking = 0,
	OwnerOnlyWithNetworking = 1,
	AnyoneSingleUserWithNetworking = 2
};

UCLASS(EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UCrackableActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCrackableActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void SetCracked(bool NewCracked);
	UFUNCTION(BlueprintCallable)
		bool GetCracked();
	UFUNCTION(BlueprintCallable)
		bool GetFullyClosed();
	UFUNCTION(BlueprintCallable)
		bool GetFullyOpen();
	UFUNCTION(BlueprintCallable)
		bool CanClickToClose();
	UFUNCTION(BlueprintCallable)
		FTransform GetClosedRelativeTransform();
	UFUNCTION(BlueprintCallable)
		void SetClosedRelativeTransform(FTransform ClosedRelativeTransform);
	UFUNCTION(BlueprintCallable)
		bool IsExaminable();
	UFUNCTION(BlueprintCallable)
		bool CracksOnlyOnExamine();
	UFUNCTION(BlueprintCallable)
		void OnParentCrackedChanged(UCrackableActorComponent* parentCrackableActorComponent, bool bParentCracked);
	UFUNCTION(BlueprintCallable)
		void OnRep_Cracked();
	UFUNCTION(BlueprintCallable)
		void OnClickUnhandled();
	UFUNCTION(BlueprintCallable)
		void OnRep_StartingRelativeTransform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FOnCrackedStateChanged OnCrackedChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FOnCrackedStateChanged OnFullyCrackedOrClosed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnExaminableChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CrackingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECrackableActorMethod Method;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString OpenSoundEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CloseSoundEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECrackableActorNetworkingPolicy NetworkingPolicy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ClientScaleWhenCracked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ScreenScaleRatio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CameraSpaceOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HoverHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HideThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PivotAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform StartingRelativeTransform;
};
