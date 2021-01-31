// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClickableComponent.generated.h"

UENUM(BlueprintType)
enum class EUseContext : uint8 {
	UC_Use = 0,
	UC_Toggle = 1,
	UC_TurnOn = 2,
	UC_TurnOff = 3,
	UC_ChangeColor = 4,
	UC_Detonate = 5,
	UC_Ignite = 6,
	UC_Launch = 7,
	UC_Print = 8,
	UC_SitDown = 9,
	UC_StandUp = 10,
	UC_Flip = 11,
	UC_TakeOff = 12,
	UC_LiftOff = 13,
	UC_Resupply = 14,
	UC_Research = 15,
	UC_Smelt = 16,
	UC_Extract = 17,
	UC_Catalyze = 18,
	UC_Condense = 19,
	UC_Trade = 20,
	UC_Enter = 21,
	UC_Exit = 22,
	UC_Land = 23,
	UC_Pack = 24,
	UC_Unpack = 25,
	UC_Equip = 26,
	UC_Unequip = 27,
	UC_Start = 28,
	UC_Stop = 29,
	UC_Pause = 30,
	UC_Cancel = 31,
	UC_Load = 32,
	UC_Unload = 33,
	UC_Transfer = 34,
	UC_Place = 35,
	UC_Deploy = 36,
	UC_Plant = 37,
	UC_AddToCatalog = 38,
	UC_Scan = 39,
	UC_Examine = 40,
	UC_Gaze = 41,
	UC_Activate = 42,
	UC_Select = 43,
	UC_Expand = 44,
	UC_Collapse = 45,
	UC_TakePhoto = 46,
	UC_EnableDepositSlot = 47,
	UC_EnableWithdrawalSlot = 48,
	UC_CycleModes = 49,
	UC_Configure = 50,
	UC_EnableOutput = 51,
	UC_DisableOutput = 52,
	UC_Lock = 53,
	UC_Unlock = 54
};

UCLASS(EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UClickableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClickableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
		EUseContext GetActiveUseContext();
	UFUNCTION(BlueprintCallable)
		void SetActiveUseContext(EUseContext NewUseContext);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool BackpackInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ShowPrimaryIndicator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ShowPrimaryIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CaptureDeformTool;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EncapsulateChildren;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DisablePrimitiveClicks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ReplaceChildren;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AllowNonOwnerClicks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LocalPrimitiveClicksOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CaptureViewActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UnencapsulateChildren;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Unclickable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool NoGamepadAutoselect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Unmovable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSlowVirtualCursorOnHover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bExcludeNonInteractPrimitivesFromGamepadAutoFocus = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasUseInteractionByDefault = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasAuxSlotUseByDefault;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasActuatorUseByDefault;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasUseWhilePlayerDriving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasInfoOnlyTooltipWhilePlayerDriving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UseActionRequriesHold = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUseOverridePivotOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bPreRepUseAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EUseContext DefaultUseContext = EUseContext::UC_Use;
};
