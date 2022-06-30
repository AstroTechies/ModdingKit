#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsState.h"
#include "PhysicsComponent.generated.h"

class AActor;
class UPhysicsComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPhysicsComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(ReplicatedUsing = OnRep_PhysicsState)
    FPhysicsState PhysicsState;

public:
    UPhysicsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetTraceEnabled(bool Enabled);

    UFUNCTION(BlueprintCallable)
    void SetPhysicsEnabled(bool Enabled);

    UFUNCTION(BlueprintCallable)
    void SetCollisionEnabled(bool Enabled);

protected:
    UFUNCTION()
    void OnRep_PhysicsState();

public:
    UFUNCTION(BlueprintPure)
    static UPhysicsComponent *GetActorPhysicsComponent(AActor *Actor);
};
