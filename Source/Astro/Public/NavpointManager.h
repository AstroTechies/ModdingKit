#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Navpoint.h"
#include "NavpointManager.generated.h"

class AActor;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UNavpointManager : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(ReplicatedUsing = OnRep_Navpoints)
    TArray<FNavpoint> Navpoints;

    UPROPERTY()
    TArray<TWeakObjectPtr<AActor>> SnailNavpointBuffTargets;

public:
    UNavpointManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_Navpoints();
};
