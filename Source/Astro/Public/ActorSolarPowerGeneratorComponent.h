#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "ESolarGeneratorSunTrackingBehavior.h"
#include "ActorSolarPowerGeneratorComponent.generated.h"

class UPowerComponent;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorSolarPowerGeneratorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference CastComponentRef;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SunFacingSolarPanelRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPowerOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPowerOutput;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SolarPanelShouldTrackSun: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESolarGeneratorSunTrackingBehavior SunTrackingBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunFacingRotationLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SolarPanelRotatorInterpolationStrength;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CastComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SunFacingSolarPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
public:
    UActorSolarPowerGeneratorComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnSpawnedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void OnReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnPlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleStoppedGeneratingPower();
    
    UFUNCTION(BlueprintCallable)
    void HandleStartedGeneratingPower();
    
    UFUNCTION(BlueprintCallable)
    void HandlePickedUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(BlueprintCallable)
    void HandleDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
};

