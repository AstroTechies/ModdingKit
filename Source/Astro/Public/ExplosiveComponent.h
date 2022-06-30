#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ExplosiveComponent.generated.h"

class AActor;
class UDamageType;
class UExplosiveEffectsConfig;
class UObject;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UExplosiveComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Power;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float AutoResourceGenerationPercentage;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CombineExplosionsRadiusRatio;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float ExplosionRadiusCraterScale;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float PowerToRadiusScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UDamageType> DamageTypeClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 IsEnabled : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UExplosiveEffectsConfig *EffectsConfig;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CombinedPower;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CombinedRadius;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector CombinedLocation;

public:
    UExplosiveComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDetonationTimerPaused(bool bIsPaused);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDetonationTimer(float DeltaTime);

protected:
    UFUNCTION(NetMulticast, Unreliable)
    void MulticastWreckageDestroyAudio(FTransform xform, UObject *contextObject);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool ExplosiveDestroyActor(AActor *ToDestroy, bool GetOutermostActor);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DoExplosionDeformation(const FVector Location, float Radius);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DoBlastDamage(const FVector Location, float Radius, float Intensity);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Detonate();

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DamageActor(AActor *Actor, const FVector Direction, float Intensity);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void CancelDetonationTimer();
};
