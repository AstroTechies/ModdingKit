#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageSignalDelegate.h"
#include "SignalDelegate.h"
#include "DamageComponent.generated.h"

class AActor;
class UDamageComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDamageComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Indestructible;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageSignal DamageSignal;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal KillSignal;
    
    UDamageComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool Kill(bool ignoreIndestructible);
    
    UFUNCTION(BlueprintCallable)
    void DealDamage(float Amount);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIndestructible(bool bIndestructible);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UDamageComponent* ActorDamageComponent(AActor* Actor);
    
};

