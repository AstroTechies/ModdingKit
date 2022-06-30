#pragma once
#include "CoreMinimal.h"
#include "GameSettingsAudioOptions.generated.h"

USTRUCT(BlueprintType)
struct FGameSettingsAudioOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float MasterVolume;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float MusicVolume;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float SfxVolume;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float VoiceVolume;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float AmbientVolume;
    
    ASTRO_API FGameSettingsAudioOptions();
};

