#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "GameSettingsAudioOptions.h"
#include "GameSettingsGraphicsOptions.h"
#include "GameSettingsDisplayOptions.h"
#include "GameSettingsControlsOptions.h"
#include "GameSettingsDataStatics.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UGameSettingsDataStatics : public UBlueprintFunctionLibrary {
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

