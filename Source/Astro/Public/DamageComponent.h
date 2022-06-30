#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageSignalDelegate.h"
#include "SignalDelegate.h"
#include "DamageComponent.generated.h"

class AActor;
class UDamageComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDamageComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool Indestructible;

    UPROPERTY(BlueprintAssignable)
    FDamageSignal DamageSignal;

    UPROPERTY(BlueprintAssignable)
    FSignal KillSignal;

    UDamageComponent();
    UFUNCTION(BlueprintCallable)
    bool Kill(bool ignoreIndestructible);

    UFUNCTION(BlueprintCallable)
    void DealDamage(float Amount);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIndestructible(bool bIndestructible);

    UFUNCTION(BlueprintPure)
    static UDamageComponent *ActorDamageComponent(AActor *Actor);
};
