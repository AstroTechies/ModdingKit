#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "CrackedActivationComponent.generated.h"

class AActor;
class UActivation;
class UCrackedActivationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCrackedActivationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* Activation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrackedValue;
    
    UCrackedActivationComponent();
private:
    UFUNCTION()
    void OnCracked();
    
    UFUNCTION()
    void OnClosed();
    
public:
    UFUNCTION(BlueprintPure)
    static UCrackedActivationComponent* ActorCrackedActivationComponent(AActor* Actor);
    
};

