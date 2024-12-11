#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsState.h"
#include "PhysicsComponent.generated.h"

class AActor;
class UPhysicsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPhysicsComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PhysicsState, meta=(AllowPrivateAccess=true))
    FPhysicsState PhysicsState;
    
public:
    UPhysicsComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetTraceEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetPhysicsEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetCollisionEnabled(bool Enabled);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_PhysicsState();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPhysicsComponent* GetActorPhysicsComponent(AActor* Actor);
    
};

