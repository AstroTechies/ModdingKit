#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ESolarGeneratorSunTrackingBehavior.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ActorSolarPowerGeneratorComponent.generated.h"

class UPrimitiveComponent;
class USceneComponent;
class UPowerComponent;

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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* CastComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* SunFacingSolarPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
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
    void HandleDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
};

