// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "GameFramework/GameUserSettings.h"
#include "GameFramework/PlayerInput.h"
#include "AstroGameUserSettings.generated.h"

class APlayerController;
struct FKey;

UENUM(BlueprintType)
enum class EAstroDiscreteInputOptionPlayerFacing : uint8
{
	Invalid = 0,
	Forward = 1,
	Backward = 2,
	Left = 3,
	Right = 4,
	RoverForward = 5,
	RoverReverse = 6,
	Sprint = 7,
	Jump = 8,
	TerrainTool = 9,
	Backpack = 10,
	ContextLeft = 11,
	ContextRight = 12,
	TerrainAddModifier = 13,
	TerrainFlattenModifier = 14,
	Tether = 15,
	Joy = 16,
	Happy = 17,
	Wave = 18,
	What = 19,
	Use = 20,
	Catalog = 21,
	ToggleCreativeDeformToolMenu = 22,
	DeleteActiveMultiToolItem = 23,
	DuplicateActiveMultiToolItem = 24,
	ChangeDeformBrushSizeModifier = 25,
	ChangeDeformBrushStrengthModifier = 26
};

UENUM(BlueprintType)
enum class EAstroWindowMode : uint8 {
	Fullscreen = 0,
	WindowedFullscreen = 1,
	Windowed = 2,
	NumWindowModes = 3
};

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void ApplyAudioSettings();
	UFUNCTION(BlueprintCallable)
		void PreviewAudioSettings(float musicVol, float sfxVol, float voiceVol, float ambientVol);
	UFUNCTION(BlueprintCallable)
		void SetAstroWindowMode(EAstroWindowMode InAstroWindowMode);
	UFUNCTION(BlueprintCallable)
		float BrightnessToGamma(int InBrightness);
	UFUNCTION(BlueprintCallable)
		void SetUseLegacyAddMode(bool inUseLegacyAddMode, APlayerController* player);
	UFUNCTION(BlueprintCallable)
		void SetVehiclesUseYawAirControls(bool inUseYawAirControls, APlayerController* player);
	UFUNCTION(BlueprintCallable)
		void SetupInputMappings(APlayerController* PlayController);
	UFUNCTION(BlueprintCallable)
		void AssignInputAxisMapping(FKey key, FName axisName, float scale, bool bTryToAddCustomInputMapping);
	UFUNCTION(BlueprintCallable)
		void RemoveInputAxisMapping(FKey Key, FName AxisName, float Scale);
	UFUNCTION(BlueprintCallable)
		void AttemptRebindInput(APlayerController* controller, FKey key, FKey oldKey, FName inputName, bool isAxis, float scale);
	UFUNCTION(BlueprintCallable)
		TArray<FInputAxisKeyMapping> GetInputAxisMappingKeys(FName AxisName, float Scale, bool IgnoreScale);
	UFUNCTION(BlueprintCallable)
		TArray<FInputAxisKeyMapping> GetInputAxisMappings(FKey Key);
	UFUNCTION(BlueprintCallable)
		void AssignInputActionMapping(FKey key, FName actionName, bool bTryToAddCustomInputMapping);
	UFUNCTION(BlueprintCallable)
		void RemoveInputActionMapping(FKey Key, FName ActionName);
	UFUNCTION(BlueprintCallable)
		TArray<FInputActionKeyMapping> GetInputActionMappingKeys(FName ActionName);
	UFUNCTION(BlueprintCallable)
		TArray<FName> GetInputActionMappingNames(FKey Key);
	UFUNCTION(BlueprintCallable)
		void ApplySensitivitySettings(APlayerController* PlayController);
	UFUNCTION(BlueprintCallable)
		bool DoesKeyMatchActionMapping(FName ActionName, FKey Key);
	UFUNCTION(BlueprintCallable)
		void RestoreInputDefaults(APlayerController* PlayController);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static UAstroGameUserSettings* GetAstroGameUserSettings();
	UFUNCTION(BlueprintCallable)
		void SetRebindableInputActions(TArray<EAstroDiscreteInputOptionPlayerFacing> PlayerFacingRebindableInputActions);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnNonResolutionSettingsChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnableSignal OnUseLegacyAddModeChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Language;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Brightness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CloudQuality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MouseSensitivity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MasterVol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MusicVol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SoundFXVol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float VoiceVol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AmbientVol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InvertedCameraYAxixMouse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHoldToSprintMouse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InvertedCameraYAxisGamepad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHoldToSprintGamepad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUseLegacyAddMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bVehiclesUseAbsoluteSteering;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bVehiclesUseYawAirControls;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 NumTimesCreativeTutorialShown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AllowInitialPlanetSelection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInputActionKeyMapping> ActionMappings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInputAxisKeyMapping> AxisMappings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInputActionKeyMapping> ActiveActionMappings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInputAxisKeyMapping> ActiveAxisMappings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> RebindableInputActions;
};
