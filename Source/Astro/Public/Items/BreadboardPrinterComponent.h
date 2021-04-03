// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PhysicalItem.h"
#include "Utilities/ActivationSignals.h"
#include "Slots/SlotReference.h"
#include "Components/ActorComponent.h"
#include "BreadboardPrinterComponent.generated.h"

class UPrinterComponent;
class UPowerComponent;
class UClickableComponent;
class USkeletalMeshComponent;
class USphereComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UBreadboardPrinterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBreadboardPrinterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintShaderThickness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanPrintToSelfPlatform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference GroundOutputSlotRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> PrintSpeedsByTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintSpeedScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintSurfaceRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float OutOfRangeDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AutoShutdownEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ActivationRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ExtensionLerpThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CalculatePrintheadAnimationValues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ExtensionLerpSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HeightLerpSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName PrintheadNeutralSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName PrintheadDeployedSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName PrintheadActualSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* PrintAreaRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* GroundOutputSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* PrinterMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* PrintAreaCollider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool PrintingOntoItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RoomToPrint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintheadHeight_Current;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintheadExtension_Current;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APhysicalItem* OwnerPhysicalItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPrinterComponent* PrinterComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPowerComponent* PowerComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClickableComponent* ClickableComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<APhysicalItem> SelectedBlueprint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bOverlapListInitialized;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference SelectedOutputSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float InitialPrintSlotOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnAnimationStateChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnableSignal OnProductionModeChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnableSignal OnAutoTerminateProductionModeChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSet<APhysicalItem *> PlatformsInRange;
};
