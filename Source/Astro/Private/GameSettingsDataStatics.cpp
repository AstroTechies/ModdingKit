#include "GameSettingsDataStatics.h"

UGameSettingsDataStatics::UGameSettingsDataStatics() {
}

FGameSettingsGraphicsOptions UGameSettingsDataStatics::GetGraphicsOptions() {
    return FGameSettingsGraphicsOptions{};
}

FGameSettingsDisplayOptions UGameSettingsDataStatics::GetDisplayOptions() {
    return FGameSettingsDisplayOptions{};
}

FGameSettingsControlsOptions UGameSettingsDataStatics::GetControlsOptions() {
    return FGameSettingsControlsOptions{};
}

FGameSettingsAudioOptions UGameSettingsDataStatics::GetAudioOptions() {
    return FGameSettingsAudioOptions{};
}


