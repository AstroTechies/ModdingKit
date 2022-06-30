#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ExplosiveEffectsConfigPair.h"
#include "ExplosiveEffectsConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UExplosiveEffectsConfig : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString ExplosionAudioEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FExplosiveEffectsConfigPair> EffectByPowerLevel;

    UExplosiveEffectsConfig();
};
