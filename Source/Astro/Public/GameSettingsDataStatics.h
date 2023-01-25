#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "GameSettingsAudioOptions.h"
#include "GameSettingsControlsOptions.h"
#include "GameSettingsDisplayOptions.h"
#include "GameSettingsGraphicsOptions.h"
#include "GameSettingsDataStatics.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UGameSettingsDataStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGameSettingsDataStatics();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameSettingsGraphicsOptions GetGraphicsOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameSettingsDisplayOptions GetDisplayOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameSettingsControlsOptions GetControlsOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameSettingsAudioOptions GetAudioOptions();
    
};

