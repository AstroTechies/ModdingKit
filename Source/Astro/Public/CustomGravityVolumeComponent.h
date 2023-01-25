#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "Components/SceneComponent.h"
#include "CustomGravityVolumeComponent.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCustomGravityVolumeComponent : public USceneComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GravityVolumeComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* GravityVolume;
    
public:
    UCustomGravityVolumeComponent();
    UFUNCTION(BlueprintCallable)
    void OnComponentExitedCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnComponentEnteredCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

