#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "ExplosiveEffectsConfigPair.h"
#include "ExplosiveEffectsConfig.generated.h"

UCLASS(Blueprintable)
class UExplosiveEffectsConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ExplosionAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExplosiveEffectsConfigPair> EffectByPowerLevel;
    
    UExplosiveEffectsConfig();
};

