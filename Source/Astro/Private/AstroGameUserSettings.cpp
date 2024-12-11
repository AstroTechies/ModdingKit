#include "AstroGameUserSettings.h"

UAstroGameUserSettings::UAstroGameUserSettings() {
    this->Brightness = 0;
    this->CloudQuality = 0;
    this->MouseSensitivity = 11;
    this->MasterVol = 0.80f;
    this->MusicVol = 0.80f;
    this->SoundFXVol = 0.80f;
    this->VoiceVol = 0.80f;
    this->AmbientVol = 0.80f;
    this->InvertedCameraYAxixMouse = false;
    this->bHoldToSprintMouse = true;
    this->bHoldToOrbitCamera = true;
    this->InvertedCameraYAxisGamepad = false;
    this->bHoldToSprintGamepad = false;
    this->bHoldToVirtualCursorGamepad = true;
    this->bUseLegacyAddMode = false;
    this->bSelectionWheelRequiresHold = true;
    this->bVehiclesUseAbsoluteSteering = true;
    this->bVehiclesUseYawAirControls = false;
    this->MaxPlayers = 4;
    this->NumTimesCreativeTutorialShown = 3;
    this->NumTimesAdventureTutorialShown = 3;
    this->AllowInitialPlanetSelection = false;
    this->FOVOffset = 0;
    this->HQTerrain = false;
    this->HQTerrainDithering = false;
    this->HQLighting = 0;
    this->HQViewDistance = 0;
    this->HQDetail = 0;
    this->HQShadowCasting = 0;
    this->AllowPS4CrossNetworkPlay = false;
    this->CompassCameraTilt = 25.00f;
    this->CompassScale = 1.00f;
    this->IgnoreBindingKeys.AddDefaulted(11);
}

void UAstroGameUserSettings::UpdateHQTerrainMaterials() {
}

void UAstroGameUserSettings::SetWindowMode(TEnumAsByte<EWindowMode::Type> InWindowMode) {
}

void UAstroGameUserSettings::SetVSync(bool InbVSync) {
}

void UAstroGameUserSettings::SetVoiceVolume(float InVoiceVolume) {
}

void UAstroGameUserSettings::SetVehiclesUseYawAirControls(bool InUseYawAirControls, APlayerController* Player) {
}

void UAstroGameUserSettings::SetVehiclesUseAbsoluteSteering(bool InUseAbsSteering) {
}

void UAstroGameUserSettings::SetUseLegacyAddMode(bool inUseLegacyAddMode, APlayerController* Player) {
}

void UAstroGameUserSettings::SetupInputMappings(APlayerController* PlayController) {
}

void UAstroGameUserSettings::SetSfxVolume(float InSfxVolume) {
}

void UAstroGameUserSettings::SetSelectionWheelRequiresHold(bool selectionWheelRequiresHold) {
}

void UAstroGameUserSettings::SetRebindableInputActionsGamepad(TArray<EAstroDiscreteInputOptionPlayerFacing> PlayerFacingRebindableInputActions) {
}

void UAstroGameUserSettings::SetRebindableInputActions(TArray<EAstroDiscreteInputOptionPlayerFacing> PlayerFacingRebindableInputActions) {
}

void UAstroGameUserSettings::SetMusicVolume(float InMusicVolume) {
}

void UAstroGameUserSettings::SetMouseSensitivity(int32 InMouseSensitivity) {
}

void UAstroGameUserSettings::SetMaxPlayers(int32 InMaxPlayers) {
}

void UAstroGameUserSettings::SetMasterVolume(float InMasterVolume) {
}

void UAstroGameUserSettings::SetLanguage(const FString& InLanguage) {
}

void UAstroGameUserSettings::SetInvertedCameraYAxisMouse(bool InInvertedCameraYAxixMouse) {
}

void UAstroGameUserSettings::SetInvertedCameraYAxisGamepad(bool InInvertedCameraYAxisGamepad) {
}

void UAstroGameUserSettings::SetHQViewDistance(int32 InHQViewDistance) {
}

void UAstroGameUserSettings::SetHQTerrainDithering(bool InHQTerrainDithering) {
}

void UAstroGameUserSettings::SetHQTerrain(bool InHQTerrain) {
}

void UAstroGameUserSettings::SetHQShadowCasting(int32 InHQShadowCasting) {
}

void UAstroGameUserSettings::SetHQLighting(int32 InHQLighting) {
}

void UAstroGameUserSettings::SetHQDetail(int32 InHQDetail) {
}

void UAstroGameUserSettings::SetHoldToVirtualCursorGamepad(bool InHoldToVirtualCursorGamepad) {
}

void UAstroGameUserSettings::SetHoldToSprintMouse(bool InHoldToSprint) {
}

void UAstroGameUserSettings::SetHoldToSprintGamepad(bool InHoldToSprint) {
}

void UAstroGameUserSettings::SetHoldToOrbitCamera(bool InHoldToOrbitCamera) {
}

void UAstroGameUserSettings::SetFpsLimit(float InFpsLimit) {
}

void UAstroGameUserSettings::SetFOVOffset(int32 Offset) {
}

void UAstroGameUserSettings::SetCompassScale(float NewCompassScale) {
}

void UAstroGameUserSettings::SetCompassCameraTilt(float NewCompassCameraTilt) {
}

void UAstroGameUserSettings::SetCloudQuality(int32 InCloudQuality) {
}

void UAstroGameUserSettings::SetBrightness(int32 InBrightness) {
}

void UAstroGameUserSettings::SetAstroWindowMode(EAstroWindowMode InAstroWindowMode) {
}

void UAstroGameUserSettings::SetAmbientVolume(float InAmbientVolume) {
}

void UAstroGameUserSettings::SetAllowPS4CrossNetworkPlay(bool InAllowPS4CrossNetworkPlay) {
}

void UAstroGameUserSettings::SetAllowInitialPlanetSelection(bool InAllowInitialPlanetSelection) {
}

void UAstroGameUserSettings::RestoreInputDefaults(APlayerController* PlayController, bool ForGamepad) {
}

void UAstroGameUserSettings::ResetNumTimesCreativeTutorialShown() {
}

void UAstroGameUserSettings::ResetNumTimesAdventureTutorialShown() {
}

void UAstroGameUserSettings::RemoveInputAxisMapping(FKey Key, FName AxisName, float Scale, bool ForGamepad) {
}

void UAstroGameUserSettings::RemoveInputActionMapping(FKey Key, FName ActionName, bool ForGamepad) {
}

void UAstroGameUserSettings::PreviewAudioSettings(float NewMusicVol, float sfxVol, float NewVoiceVol, float NewAmbientVol) {
}

void UAstroGameUserSettings::IncrementNumTimesCreativeTutorialShown() {
}

void UAstroGameUserSettings::IncrementNumTimesAdventureTutorialShown() {
}

TEnumAsByte<EWindowMode::Type> UAstroGameUserSettings::GetWindowMode() const {
    return EWindowMode::Fullscreen;
}

bool UAstroGameUserSettings::GetVSync() const {
    return false;
}

float UAstroGameUserSettings::GetVoiceVolume() const {
    return 0.0f;
}

bool UAstroGameUserSettings::GetVehiclesUseYawAirControls() const {
    return false;
}

bool UAstroGameUserSettings::GetVehiclesUseAbsoluteSteering() const {
    return false;
}

bool UAstroGameUserSettings::GetUseLegacyAddMode() const {
    return false;
}

float UAstroGameUserSettings::GetSfxVolume() const {
    return 0.0f;
}

bool UAstroGameUserSettings::GetSelectionWheelRequiresHold() const {
    return false;
}

uint8 UAstroGameUserSettings::GetNumTimesCreativeTutorialShown() const {
    return 0;
}

uint8 UAstroGameUserSettings::GetNumTimesAdventureTutorialShown() const {
    return 0;
}

float UAstroGameUserSettings::GetMusicVolume() const {
    return 0.0f;
}

int32 UAstroGameUserSettings::GetMouseSensitivity() const {
    return 0;
}

int32 UAstroGameUserSettings::GetMaxPlayers() const {
    return 0;
}

float UAstroGameUserSettings::GetMasterVolume() const {
    return 0.0f;
}

FString UAstroGameUserSettings::GetLanguage() const {
    return TEXT("");
}

bool UAstroGameUserSettings::GetInvertedCameraYAxisMouse() const {
    return false;
}

bool UAstroGameUserSettings::GetInvertedCameraYAxisGamepad() const {
    return false;
}

TArray<FInputAxisKeyMapping> UAstroGameUserSettings::GetInputAxisMappings(FKey Key) const {
    return TArray<FInputAxisKeyMapping>();
}

TArray<FInputAxisKeyMapping> UAstroGameUserSettings::GetInputAxisMappingKeys(FName AxisName, float Scale, bool IgnoreScale, bool ForGampad) const {
    return TArray<FInputAxisKeyMapping>();
}

TArray<FName> UAstroGameUserSettings::GetInputActionMappingNames(FKey Key) const {
    return TArray<FName>();
}

TArray<FInputActionKeyMapping> UAstroGameUserSettings::GetInputActionMappingKeys(FName ActionName, bool ForGamepad) const {
    return TArray<FInputActionKeyMapping>();
}

int32 UAstroGameUserSettings::GetHQViewDistance() const {
    return 0;
}

bool UAstroGameUserSettings::GetHQTerrainDithering() const {
    return false;
}

bool UAstroGameUserSettings::GetHQTerrain() const {
    return false;
}

int32 UAstroGameUserSettings::GetHQShadowCasting() const {
    return 0;
}

int32 UAstroGameUserSettings::GetHQLighting() const {
    return 0;
}

int32 UAstroGameUserSettings::GetHQDetail() const {
    return 0;
}

bool UAstroGameUserSettings::GetHoldToVirtualCursorGamepad() const {
    return false;
}

bool UAstroGameUserSettings::GetHoldToSprintMouse() const {
    return false;
}

bool UAstroGameUserSettings::GetHoldToSprintGamepad() const {
    return false;
}

bool UAstroGameUserSettings::GetHoldToOrbitCamera() const {
    return false;
}

float UAstroGameUserSettings::GetFpsLimit() {
    return 0.0f;
}

int32 UAstroGameUserSettings::GetFOVOffset() const {
    return 0;
}

float UAstroGameUserSettings::GetCompassScale() const {
    return 0.0f;
}

float UAstroGameUserSettings::GetCompassCameraTilt() const {
    return 0.0f;
}

int32 UAstroGameUserSettings::GetCloudQuality() const {
    return 0;
}

int32 UAstroGameUserSettings::GetBrightness() const {
    return 0;
}

UAstroGameUserSettings* UAstroGameUserSettings::GetAstroGameUserSettings() {
    return NULL;
}

float UAstroGameUserSettings::GetAmbientVolume() const {
    return 0.0f;
}

bool UAstroGameUserSettings::GetAllowPS4CrossNetworkPlay() const {
    return false;
}

bool UAstroGameUserSettings::GetAllowInitialPlanetSelection() const {
    return false;
}

bool UAstroGameUserSettings::DoesKeyMatchActionMapping(FName ActionName, FKey Key) {
    return false;
}

float UAstroGameUserSettings::BrightnessToGamma(int32 InBrightness) {
    return 0.0f;
}

void UAstroGameUserSettings::AttemptRebindInputGamepad(APlayerController* Controller, FKey newKey, FKey oldKey, FName InputName, bool isAxis, float Scale) {
}

void UAstroGameUserSettings::AttemptRebindInput(APlayerController* Controller, FKey newKey, FKey oldKey, FName InputName, bool isAxis, float Scale) {
}

void UAstroGameUserSettings::AssignInputAxisMapping(FKey Key, FName AxisName, float Scale, bool bTryToAddCustomInputMapping) {
}

void UAstroGameUserSettings::AssignInputActionMapping(FKey Key, FName ActionName, bool bTryToAddCustomInputMapping) {
}

void UAstroGameUserSettings::ApplySensitivitySettings(APlayerController* PlayController) {
}

void UAstroGameUserSettings::ApplyQualitySettingsConsole() {
}

void UAstroGameUserSettings::ApplyAudioSettings() {
}


