#pragma once
#include "CoreMinimal.h"
#include "PhysicsState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
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
    UPhysicsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    static UPhysicsComponent* GetActorPhysicsComponent(AActor* Actor);
    
};

