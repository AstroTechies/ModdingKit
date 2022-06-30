#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "ControlledVehicleMovement.generated.h"

class UPowerComponent;
class UWheeledChassisComponent;
class APlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlledVehicleMovement : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float MovingValue;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float TargetMovingValue;

    UPROPERTY(EditDefaultsOnly)
    bool DoNotBindInputToControlComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float RawThrottleValue;

private:
    UPROPERTY(Replicated, Transient)
    uint8 bAuthoritativeEnabled : 1;

    UPROPERTY(Transient)
    bool bEnabled;

    UPROPERTY(Transient)
    bool bPhysicsEnabledCached;

    UPROPERTY(Export, Transient)
    UWheeledChassisComponent *WheeledChassis;

    UPROPERTY(Export, Transient)
    TArray<UPowerComponent *> PowerComponents;

public:
    UControlledVehicleMovement();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void SetControlled(bool IsControlled);

private:
    UFUNCTION(Reliable, Server, WithValidation)
    void SetAuthorityControlled(bool IsControlled);

public:
    UFUNCTION()
    void OnUnmanned();

    UFUNCTION()
    void OnMove(APlayerController *Controller, const FVector &Direction);
};
