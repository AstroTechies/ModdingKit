#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "WindPowerGeneratorReplicationData.h"
#include "ActorWindPowerGeneratorComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorWindPowerGeneratorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWindPowerAnimationDataChanged, FVector, WindNormal, float, WindSpeed);

protected:
    UPROPERTY(EditAnywhere)
    float DebugLineWindVectorVerticalOffset;

    UPROPERTY(EditAnywhere)
    float DebugLineWindDirectionScale;

    UPROPERTY(BlueprintAssignable)
    FOnWindPowerAnimationDataChanged OnWindPowerAnimationDataChanged;

    UPROPERTY(EditDefaultsOnly)
    float MinPowerOutput;

    UPROPERTY(EditDefaultsOnly)
    float MaxPowerOutput;

    UPROPERTY(EditDefaultsOnly)
    float WindSpeedAnimationInterpolationStrength;

    UPROPERTY(EditDefaultsOnly)
    float WindDirAnimationInterpolationStrength;

private:
    UPROPERTY(ReplicatedUsing = OnRep_AnimatedWindVec)
    FWindPowerGeneratorReplicationData WindPowerAnimationData;

public:
    UActorWindPowerGeneratorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnRep_AnimatedWindVec();
};
