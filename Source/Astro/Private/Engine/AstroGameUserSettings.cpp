// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroGameUserSettings.h"

void UAstroGameUserSettings::ApplyAudioSettings()
{

}

void UAstroGameUserSettings::PreviewAudioSettings(float musicVol, float sfxVol, float voiceVol, float ambientVol)
{

}

void UAstroGameUserSettings::SetAstroWindowMode(EAstroWindowMode InAstroWindowMode)
{

}

float UAstroGameUserSettings::BrightnessToGamma(int InBrightness)
{
	return 0;
}

void UAstroGameUserSettings::SetUseLegacyAddMode(bool inUseLegacyAddMode, APlayerController* player)
{

}

void UAstroGameUserSettings::SetVehiclesUseYawAirControls(bool inUseYawAirControls, APlayerController* player)
{

}

void UAstroGameUserSettings::SetupInputMappings(APlayerController* PlayController)
{

}

void UAstroGameUserSettings::AssignInputAxisMapping(FKey key, FName axisName, float scale, bool bTryToAddCustomInputMapping)
{

}

void UAstroGameUserSettings::RemoveInputAxisMapping(FKey Key, FName AxisName, float Scale)
{

}

void UAstroGameUserSettings::AttemptRebindInput(APlayerController* controller, FKey key, FKey oldKey, FName inputName, bool isAxis, float scale)
{

}

TArray<FInputAxisKeyMapping> UAstroGameUserSettings::GetInputAxisMappingKeys(FName AxisName, float Scale, bool IgnoreScale)
{
	TArray<FInputAxisKeyMapping> x;
	return x;
}

TArray<FInputAxisKeyMapping> UAstroGameUserSettings::GetInputAxisMappings(FKey Key)
{
	TArray<FInputAxisKeyMapping> x;
	return x;
}

void UAstroGameUserSettings::AssignInputActionMapping(FKey key, FName actionName, bool bTryToAddCustomInputMapping)
{

}

void UAstroGameUserSettings::RemoveInputActionMapping(FKey Key, FName ActionName)
{

}

TArray<FInputActionKeyMapping> UAstroGameUserSettings::GetInputActionMappingKeys(FName ActionName)
{
	TArray<FInputActionKeyMapping> x;
	return x;
}

TArray<FName> UAstroGameUserSettings::GetInputActionMappingNames(FKey Key)
{
	TArray<FName> x;
	return x;
}

void UAstroGameUserSettings::ApplySensitivitySettings(APlayerController* PlayController)
{

}

bool UAstroGameUserSettings::DoesKeyMatchActionMapping(FName ActionName, FKey Key)
{
	return false;
}

void UAstroGameUserSettings::RestoreInputDefaults(APlayerController* PlayController)
{

}

UAstroGameUserSettings* UAstroGameUserSettings::GetAstroGameUserSettings()
{
	return nullptr;
}

void UAstroGameUserSettings::SetRebindableInputActions(TArray<EAstroDiscreteInputOptionPlayerFacing> PlayerFacingRebindableInputActions)
{

}