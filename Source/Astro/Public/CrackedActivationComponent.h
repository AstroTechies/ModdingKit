#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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
    
    UCrackedActivationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnCracked();
    
    UFUNCTION(BlueprintCallable)
    void OnClosed();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UCrackedActivationComponent* ActorCrackedActivationComponent(AActor* Actor);
    
};

