#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GameFramework/GameUserSettings.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/PlayerInput.h"
#include "InputCoreTypes.h"
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "EAstroWindowMode.h"
#include "EnableSignalDelegate.h"
#include "InputReference.h"
#include "AstroGameUserSettings.generated.h"

class APlayerController;
class UAstroGameUserSettings;

UCLASS(Blueprintable, Config=Engine)
class ASTRO_API UAstroGameUserSettings : public UGameUserSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnUseLegacyAddModeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Language;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Brightness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CloudQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MouseSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MasterVol;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MusicVol;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoundFXVol;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VoiceVol;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AmbientVol;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadSpeakerVol;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertedCameraYAxixMouse;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldToSprintMouse;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldToOrbitCamera;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertedCameraYAxisGamepad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldToSprintGamepad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldToVirtualCursorGamepad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseLegacyAddMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelectionWheelRequiresHold;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVehiclesUseAbsoluteSteering;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVehiclesUseYawAirControls;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bToggleSpeakerGamepad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bToggleLightBarGamepad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bToggleRumbleGamepad;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPlayers;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 NumTimesCreativeTutorialShown;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 NumTimesAdventureTutorialShown;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 NumTimesGlitchwalkersTutorialShown;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowInitialPlanetSelection;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FOVOffset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HQTerrain;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HQTerrainDithering;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HQLighting;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HQViewDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HQDetail;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HQShadowCasting;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowPS4CrossNetworkPlay;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompassCameraTilt;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompassScale;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StormsDisabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCableSnapWarning;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> ActionMappings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputAxisKeyMapping> AxisMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> ActiveActionMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputAxisKeyMapping> ActiveAxisMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FInputReference, FInputReference> SlavedMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> IgnoreBindingKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RebindableInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
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
    void SetVehiclesUseYawAirControls(bool InUseYawAirControls, APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void SetVehiclesUseAbsoluteSteering(bool InUseAbsSteering);
    
    UFUNCTION(BlueprintCallable)
    void SetUseLegacyAddMode(bool inUseLegacyAddMode, APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void SetupInputMappings(APlayerController* PlayController);
    
    UFUNCTION(BlueprintCallable)
    void SetToggleSpeakerGamepad(bool InToggleSpeakerGamepad);
    
    UFUNCTION(BlueprintCallable)
    void SetToggleRumbleGamepad(bool InToggleRumbleGamepad);
    
    UFUNCTION(BlueprintCallable)
    void SetToggleLightBarGamepad(bool InToggleLightBarGamepad);
    
    UFUNCTION(BlueprintCallable)
    void SetStormsDisabled(bool NewStormsDisabled);
    
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
    void SetLanguage(const FString& InLanguage);
    
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
    void SetGamepadSpeakerVolume(float InGamepadSpeakerVolume);
    
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
    void SetCableSnapWarning(bool cableSnapWarning);
    
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
    void RestoreInputDefaults(APlayerController* PlayController, bool ForGamepad);
    
    UFUNCTION(BlueprintCallable)
    void ResetNumTimesGlitchwalkersTutorialShown();
    
    UFUNCTION(BlueprintCallable)
    void ResetNumTimesCreativeTutorialShown();
    
    UFUNCTION(BlueprintCallable)
    void ResetNumTimesAdventureTutorialShown();
    
    UFUNCTION(BlueprintCallable)
    void RemoveInputAxisMapping(FKey Key, FName AxisName, float Scale, bool ForGamepad);
    
    UFUNCTION(BlueprintCallable)
    void RemoveInputActionMapping(FKey Key, FName ActionName, bool ForGamepad);
    
    UFUNCTION(BlueprintCallable)
    void PreviewAudioSettings(float NewMusicVol, float sfxVol, float NewVoiceVol, float NewAmbientVol, float NewGamepadSpeakerVol);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumTimesGlitchwalkersTutorialShown();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumTimesCreativeTutorialShown();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumTimesAdventureTutorialShown();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EWindowMode::Type> GetWindowMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVSync() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVoiceVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVehiclesUseYawAirControls() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVehiclesUseAbsoluteSteering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseLegacyAddMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetToggleSpeakerGamepad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetToggleRumbleGamepad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetToggleLightBarGamepad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStormsDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSfxVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSelectionWheelRequiresHold() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNumTimesGlitchwalkersTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNumTimesCreativeTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNumTimesAdventureTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMusicVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMouseSensitivity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxPlayers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMasterVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetLanguage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInvertedCameraYAxisMouse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInvertedCameraYAxisGamepad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FInputAxisKeyMapping> GetInputAxisMappings(FKey Key) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FInputAxisKeyMapping> GetInputAxisMappingKeys(FName AxisName, float Scale, bool IgnoreScale, bool ForGampad) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetInputActionMappingNames(FKey Key) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FInputActionKeyMapping> GetInputActionMappingKeys(FName ActionName, bool ForGamepad) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHQViewDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHQTerrainDithering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHQTerrain() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHQShadowCasting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHQLighting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHQDetail() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHoldToVirtualCursorGamepad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHoldToSprintMouse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHoldToSprintGamepad() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHoldToOrbitCamera() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGamepadSpeakerVolume() const;
    
    UFUNCTION(BlueprintCallable)
    float GetFpsLimit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFOVOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCompassScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCompassCameraTilt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCloudQuality() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCableSnapWarningEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBrightness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAstroGameUserSettings* GetAstroGameUserSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAmbientVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllowPS4CrossNetworkPlay() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllowInitialPlanetSelection() const;
    
    UFUNCTION(BlueprintCallable)
    bool DoesKeyMatchActionMapping(FName ActionName, FKey Key);
    
    UFUNCTION(BlueprintCallable)
    static float BrightnessToGamma(int32 InBrightness);
    
    UFUNCTION(BlueprintCallable)
    void AttemptRebindInputGamepad(APlayerController* Controller, FKey newKey, FKey oldKey, FName InputName, bool isAxis, float Scale);
    
    UFUNCTION(BlueprintCallable)
    void AttemptRebindInput(APlayerController* Controller, FKey newKey, FKey oldKey, FName InputName, bool isAxis, float Scale);
    
    UFUNCTION(BlueprintCallable)
    void AssignInputAxisMapping(FKey Key, FName AxisName, float Scale, bool bTryToAddCustomInputMapping);
    
    UFUNCTION(BlueprintCallable)
    void AssignInputActionMapping(FKey Key, FName ActionName, bool bTryToAddCustomInputMapping);
    
    UFUNCTION(BlueprintCallable)
    void ApplySensitivitySettings(APlayerController* PlayController);
    
    UFUNCTION(BlueprintCallable)
    void ApplyQualitySettingsConsole();
    
    UFUNCTION(BlueprintCallable)
    void ApplyAudioSettings();
    
};

