#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ControlActivatorComponent.generated.h"

class AActor;
class UControlComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlActivatorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UControlComponent *ActiveControl;

private:
    UPROPERTY(ReplicatedUsing = OnRep_ControlledToolActor)
    AActor *ControlledToolActor;

    UPROPERTY(Replicated)
    AActor *PassengerToolActor;

    UPROPERTY()
    bool ChangedControlActor;

public:
    UControlActivatorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnRep_ControlledToolActor(AActor *oldActor);
};
