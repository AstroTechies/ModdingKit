#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/EngineTypes.h"
#include "CustomGravityVolumeComponent.generated.h"

class UPrimitiveComponent;
class AActor;

UCLASS(Blueprintable, Abstract, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCustomGravityVolumeComponent : public USceneComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    FName GravityVolumeComponentName;

    UPROPERTY(EditAnywhere)
    float GravityStrength;

    UPROPERTY(Export, Transient)
    UPrimitiveComponent *GravityVolume;

public:
    UCustomGravityVolumeComponent();
    UFUNCTION()
    void OnComponentExitedCustomGravityVolume(UPrimitiveComponent *volumeComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex);

    UFUNCTION()
    void OnComponentEnteredCustomGravityVolume(UPrimitiveComponent *volumeComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
