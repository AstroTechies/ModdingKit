#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "PlanetEffectRelevancyChangedDelegate.h"
#include "PlanetEffect.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPlanetEffect : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverlappingPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSimLocal: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoHandleCriticalComponents: 1;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlanetEffectRelevancyChanged OnPlanetEffectRelevancyChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> ManagedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> AutoManagedComponents;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<uint8> AutoManagedComponentFlags;
    
public:
    UPlanetEffect();
    UFUNCTION(BlueprintCallable)
    void TriggerUpdate();
    
    UFUNCTION(BlueprintCallable)
    static void SetActorIgnoreForAI(AActor* Actor, bool bSetIgnore);
    
    UFUNCTION(BlueprintCallable)
    void AddManagedComponent(UActorComponent* Component);
    
};

