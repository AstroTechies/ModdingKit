#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "PlanetEffectRelevancyChangedDelegate.h"
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
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FPlanetEffectRelevancyChanged OnPlanetEffectRelevancyChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> ManagedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> AutoManagedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint8> AutoManagedComponentFlags;
    
public:
    UPlanetEffect(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerUpdate();
    
    UFUNCTION(BlueprintCallable)
    static void SetActorIgnoreForAI(AActor* Actor, bool bSetIgnore);
    
    UFUNCTION(BlueprintCallable)
    void AddManagedComponent(UActorComponent* Component);
    
};

