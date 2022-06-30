#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GameFramework/GameUserSettings.h"
#include "EnableSignalDelegate.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/PlayerInput.h"
#include "InputReference.h"
#include "InputCoreTypes.h"
#include "EAstroWindowMode.h"
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "AstroGameUserSettings.generated.h"

class APlayerController;
class UAstroGameUserSettings;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroGameUserSettings : public UGameUserSettings
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FEnableSignal OnUseLegacyAddModeChanged;

protected:
    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FString Language;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 Brightness;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 CloudQuality;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 MouseSensitivity;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float MasterVol;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float MusicVol;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float SoundFXVol;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float VoiceVol;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float AmbientVol;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool InvertedCameraYAxixMouse;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bHoldToSprintMouse;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bHoldToOrbitCamera;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool InvertedCameraYAxisGamepad;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bHoldToSprintGamepad;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bHoldToVirtualCursorGamepad;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bUseLegacyAddMode;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bSelectionWheelRequiresHold;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bVehiclesUseAbsoluteSteering;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bVehiclesUseYawAirControls;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 MaxPlayers;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 NumTimesCreativeTutorialShown;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 NumTimesAdventureTutorialShown;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool AllowInitialPlanetSelection;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 FOVOffset;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool HQTerrain;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool HQTerrainDithering;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 HQLighting;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 HQViewDistance;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 HQDetail;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 HQShadowCasting;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool AllowPS4CrossNetworkPlay;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CompassCameraTilt;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CompassScale;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FInputActionKeyMapping> ActionMappings;

    UPROPERTY(Config, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FInputAxisKeyMapping> AxisMappings;

    UPROPERTY()
    TArray<FInputActionKeyMapping> ActiveActionMappings;

    UPROPERTY()
    TArray<FInputAxisKeyMapping> ActiveAxisMappings;

    UPROPERTY()
    TMap<FInputReference, FInputReference> SlavedMappings;

    UPROPERTY()
    TArray<FKey> IgnoreBindingKeys;

    UPROPERTY()
    TArray<FName> RebindableInputActions;

    UPROPERTY()
    TArray<FName> RebindableInputActionsGamepad;

public:
    UAstroGameUserSettings();
    UFUNCTION(BlueprintCallable)
    void UpdateHQTerrainMaterials();

    UFUNCTION(BlueprintCallable)
    void SetWindowMode(TEnumAsByte<EWindowMode::Type> InWindowMode);

    UFUNCTION(BlueprintCallable)
    void SetVSync(bool InbVSync);

    UFUNCTION(BlueprintCallable)
    void SetVoiceVolume(float InVoiceVolume);

    UFUNCTION(BlueprintCallable)
    void SetVehiclesUseYawAirControls(bool InUseYawAirControls, APlayerController *Player);

    UFUNCTION(BlueprintCallable)
    void SetVehiclesUseAbsoluteSteering(bool InUseAbsSteering);

    UFUNCTION(BlueprintCallable)
    void SetUseLegacyAddMode(bool inUseLegacyAddMode, APlayerController *Player);

    UFUNCTION(BlueprintCallable)
    void SetupInputMappings(APlayerController *PlayController);

    UFUNCTION(BlueprintCallable)
    void SetSfxVolume(float InSfxVolume);

    UFUNCTION(BlueprintCallable)
    void SetSelectionWheelRequiresHold(bool selectionWheelRequiresHold);

    UFUNCTION(BlueprintCallable)
    void SetRebindableInputActionsGamepad(TArray<EAstroDiscreteInputOptionPlayerFacing> PlayerFacingRebindableInputActions);

    UFUNCTION(BlueprintCallable)
    void SetRebindableInputActions(TArray<EAstroDiscreteInputOptionPlayerFacing> PlayerFacingRebindableInputActions);

    UFUNCTION(BlueprintCallable)
    void SetMusicVolume(float InMusicVolume);

    UFUNCTION(BlueprintCallable)
    void SetMouseSensitivity(int32 InMouseSensitivity);

    UFUNCTION(BlueprintCallable)
    void SetMaxPlayers(int32 InMaxPlayers);

    UFUNCTION(BlueprintCallable)
    void SetMasterVolume(float InMasterVolume);

    UFUNCTION(BlueprintCallable)
    void SetLanguage(const FString &InLanguage);

    UFUNCTION(BlueprintCallable)
    void SetInvertedCameraYAxisMouse(bool InInvertedCameraYAxixMouse);

    UFUNCTION(BlueprintCallable)
    void SetInvertedCameraYAxisGamepad(bool InInvertedCameraYAxisGamepad);

    UFUNCTION(BlueprintCallable)
    void SetHQViewDistance(int32 InHQViewDistance);

    UFUNCTION(BlueprintCallable)
    void SetHQTerrainDithering(bool InHQTerrainDithering);

    UFUNCTION(BlueprintCallable)
    void SetHQTerrain(bool InHQTerrain);

    UFUNCTION(BlueprintCallable)
    void SetHQShadowCasting(int32 InHQShadowCasting);

    UFUNCTION(BlueprintCallable)
    void SetHQLighting(int32 InHQLighting);

    UFUNCTION(BlueprintCallable)
    void SetHQDetail(int32 InHQDetail);

    UFUNCTION(BlueprintCallable)
    void SetHoldToVirtualCursorGamepad(bool InHoldToVirtualCursorGamepad);

    UFUNCTION(BlueprintCallable)
    void SetHoldToSprintMouse(bool InHoldToSprint);

    UFUNCTION(BlueprintCallable)
    void SetHoldToSprintGamepad(bool InHoldToSprint);

    UFUNCTION(BlueprintCallable)
    void SetHoldToOrbitCamera(bool InHoldToOrbitCamera);

    UFUNCTION(BlueprintCallable)
    void SetFpsLimit(float InFpsLimit);

    UFUNCTION(BlueprintCallable)
    void SetFOVOffset(int32 Offset);

    UFUNCTION(BlueprintCallable)
    void SetCompassScale(float NewCompassScale);

    UFUNCTION(BlueprintCallable)
    void SetCompassCameraTilt(float NewCompassCameraTilt);

    UFUNCTION(BlueprintCallable)
    void SetCloudQuality(int32 InCloudQuality);

    UFUNCTION(BlueprintCallable)
    void SetBrightness(int32 InBrightness);

    UFUNCTION(BlueprintCallable)
    void SetAstroWindowMode(EAstroWindowMode InAstroWindowMode);

    UFUNCTION(BlueprintCallable)
    void SetAmbientVolume(float InAmbientVolume);

    UFUNCTION(BlueprintCallable)
    void SetAllowPS4CrossNetworkPlay(bool InAllowPS4CrossNetworkPlay);

    UFUNCTION(BlueprintCallable)
    void SetAllowInitialPlanetSelection(bool InAllowInitialPlanetSelection);

    UFUNCTION(BlueprintCallable)
    void RestoreInputDefaults(APlayerController *PlayController, bool ForGamepad);

    UFUNCTION()
    void ResetNumTimesCreativeTutorialShown();

    UFUNCTION()
    void ResetNumTimesAdventureTutorialShown();

    UFUNCTION(BlueprintCallable)
    void RemoveInputAxisMapping(FKey Key, FName AxisName, float Scale, bool ForGamepad);

    UFUNCTION(BlueprintCallable)
    void RemoveInputActionMapping(FKey Key, FName ActionName, bool ForGamepad);

    UFUNCTION(BlueprintCallable)
    void PreviewAudioSettings(float NewMusicVol, float sfxVol, float NewVoiceVol, float NewAmbientVol);

    UFUNCTION(BlueprintCallable)
    void IncrementNumTimesCreativeTutorialShown();

    UFUNCTION(BlueprintCallable)
    void IncrementNumTimesAdventureTutorialShown();

    UFUNCTION(BlueprintPure)
    TEnumAsByte<EWindowMode::Type> GetWindowMode() const;

    UFUNCTION(BlueprintPure)
    bool GetVSync() const;

    UFUNCTION(BlueprintPure)
    float GetVoiceVolume() const;

    UFUNCTION(BlueprintPure)
    bool GetVehiclesUseYawAirControls() const;

    UFUNCTION(BlueprintPure)
    bool GetVehiclesUseAbsoluteSteering() const;

    UFUNCTION(BlueprintPure)
    bool GetUseLegacyAddMode() const;

    UFUNCTION(BlueprintPure)
    float GetSfxVolume() const;

    UFUNCTION(BlueprintPure)
    bool GetSelectionWheelRequiresHold() const;

    UFUNCTION(BlueprintPure)
    uint8 GetNumTimesCreativeTutorialShown() const;

    UFUNCTION(BlueprintPure)
    uint8 GetNumTimesAdventureTutorialShown() const;

    UFUNCTION(BlueprintPure)
    float GetMusicVolume() const;

    UFUNCTION(BlueprintPure)
    int32 GetMouseSensitivity() const;

    UFUNCTION(BlueprintPure)
    int32 GetMaxPlayers() const;

    UFUNCTION(BlueprintPure)
    float GetMasterVolume() const;

    UFUNCTION(BlueprintPure)
    FString GetLanguage() const;

    UFUNCTION(BlueprintPure)
    bool GetInvertedCameraYAxisMouse() const;

    UFUNCTION(BlueprintPure)
    bool GetInvertedCameraYAxisGamepad() const;

    UFUNCTION(BlueprintPure)
    TArray<FInputAxisKeyMapping> GetInputAxisMappings(FKey Key) const;

    UFUNCTION(BlueprintPure)
    TArray<FInputAxisKeyMapping> GetInputAxisMappingKeys(FName AxisName, float Scale, bool IgnoreScale, bool ForGampad) const;

    UFUNCTION(BlueprintPure)
    TArray<FName> GetInputActionMappingNames(FKey Key) const;

    UFUNCTION(BlueprintPure)
    TArray<FInputActionKeyMapping> GetInputActionMappingKeys(FName ActionName, bool ForGamepad) const;

    UFUNCTION(BlueprintPure)
    int32 GetHQViewDistance() const;

    UFUNCTION(BlueprintPure)
    bool GetHQTerrainDithering() const;

    UFUNCTION(BlueprintPure)
    bool GetHQTerrain() const;

    UFUNCTION(BlueprintPure)
    int32 GetHQShadowCasting() const;

    UFUNCTION(BlueprintPure)
    int32 GetHQLighting() const;

    UFUNCTION(BlueprintPure)
    int32 GetHQDetail() const;

    UFUNCTION(BlueprintPure)
    bool GetHoldToVirtualCursorGamepad() const;

    UFUNCTION(BlueprintPure)
    bool GetHoldToSprintMouse() const;

    UFUNCTION(BlueprintPure)
    bool GetHoldToSprintGamepad() const;

    UFUNCTION(BlueprintPure)
    bool GetHoldToOrbitCamera() const;

    UFUNCTION(BlueprintCallable)
    float GetFpsLimit();

    UFUNCTION(BlueprintPure)
    int32 GetFOVOffset() const;

    UFUNCTION(BlueprintPure)
    float GetCompassScale() const;

    UFUNCTION(BlueprintPure)
    float GetCompassCameraTilt() const;

    UFUNCTION(BlueprintPure)
    int32 GetCloudQuality() const;

    UFUNCTION(BlueprintPure)
    int32 GetBrightness() const;

    UFUNCTION(BlueprintPure)
    static UAstroGameUserSettings *GetAstroGameUserSettings();

    UFUNCTION(BlueprintPure)
    float GetAmbientVolume() const;

    UFUNCTION(BlueprintPure)
    bool GetAllowPS4CrossNetworkPlay() const;

    UFUNCTION(BlueprintPure)
    bool GetAllowInitialPlanetSelection() const;

    UFUNCTION(BlueprintCallable)
    bool DoesKeyMatchActionMapping(FName ActionName, FKey Key);

    UFUNCTION(BlueprintCallable)
    static float BrightnessToGamma(int32 InBrightness);

    UFUNCTION(BlueprintCallable)
    void AttemptRebindInputGamepad(APlayerController *Controller, FKey newKey, FKey oldKey, FName InputName, bool isAxis, float Scale);

    UFUNCTION(BlueprintCallable)
    void AttemptRebindInput(APlayerController *Controller, FKey newKey, FKey oldKey, FName InputName, bool isAxis, float Scale);

    UFUNCTION(BlueprintCallable)
    void AssignInputAxisMapping(FKey Key, FName AxisName, float Scale, bool bTryToAddCustomInputMapping);

    UFUNCTION(BlueprintCallable)
    void AssignInputActionMapping(FKey Key, FName ActionName, bool bTryToAddCustomInputMapping);

    UFUNCTION(BlueprintCallable)
    void ApplySensitivitySettings(APlayerController *PlayController);

    UFUNCTION(BlueprintCallable)
    void ApplyQualitySettingsConsole();

    UFUNCTION(BlueprintCallable)
    void ApplyAudioSettings();
};