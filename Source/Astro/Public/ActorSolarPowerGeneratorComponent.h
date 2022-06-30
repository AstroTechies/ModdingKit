#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ESolarGeneratorSunTrackingBehavior.h"
#include "ActorSolarPowerGeneratorComponent.generated.h"

class UPowerComponent;
class USceneComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorSolarPowerGeneratorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference CastComponentRef;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SunFacingSolarPanelRef;

    UPROPERTY(EditDefaultsOnly)
    float MinPowerOutput;

    UPROPERTY(EditDefaultsOnly)
    float MaxPowerOutput;

protected:
    UPROPERTY(EditDefaultsOnly)
    uint8 SolarPanelShouldTrackSun : 1;

    UPROPERTY(EditDefaultsOnly)
    ESolarGeneratorSunTrackingBehavior SunTrackingBehavior;

    UPROPERTY(EditDefaultsOnly)
    float SunFacingRotationLimit;

    UPROPERTY(EditDefaultsOnly)
    float SolarPanelRotatorInterpolationStrength;

private:
    UPROPERTY(Export)
    USceneComponent *CastComponent;

    UPROPERTY(Export)
    USceneComponent *SunFacingSolarPanel;

    UPROPERTY(Export)
    UPowerComponent *PowerComponent;

public:
    UActorSolarPowerGeneratorComponent();

protected:
    UFUNCTION()
    void OnSpawnedInSlot();

    UFUNCTION()
    void OnReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void OnPlacedInSlot();

    UFUNCTION()
    void HandleStoppedGeneratingPower();

    UFUNCTION()
    void HandleStartedGeneratingPower();

    UFUNCTION()
    void HandlePickedUpFromWorld(bool PhysicalMovement);

    UFUNCTION()
    void HandleDroppedInWorld(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);
};
