#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameSettingsGraphicsOptions.h"
#include "GameSettingsControlsOptions.h"
#include "GameSettingsDisplayOptions.h"
#include "GameSettingsAudioOptions.h"
#include "GameSettingsDataStatics.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UGameSettingsDataStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UGameSettingsDataStatics();
    UFUNCTION(BlueprintPure)
    static FGameSettingsGraphicsOptions GetGraphicsOptions();

    UFUNCTION(BlueprintPure)
    static FGameSettingsDisplayOptions GetDisplayOptions();

    UFUNCTION(BlueprintPure)
    static FGameSettingsControlsOptions GetControlsOptions();

    UFUNCTION(BlueprintPure)
    static FGameSettingsAudioOptions GetAudioOptions();
};
