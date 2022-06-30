#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "FollowComponent.generated.h"

class AActor;
class UFollowComponent;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UFollowComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *FollowComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool TrackFollowVelocity;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *ScaleComponent;

    UPROPERTY(EditAnywhere)
    float TargetScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ForceMultiplier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ForceDampening;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ArriveRadius;

    UPROPERTY(EditAnywhere)
    float MinLife;

    UPROPERTY(EditAnywhere)
    float MaxLife;

    UPROPERTY(BlueprintAssignable)
    FSignal OnArrived;

    UFollowComponent();
    UFUNCTION(BlueprintCallable)
    void SetFollowComponent(USceneComponent *Component);

    UFUNCTION(BlueprintCallable)
    static UFollowComponent *AddActorFollowComponent(AActor *Actor);
};