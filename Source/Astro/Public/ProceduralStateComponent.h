#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralActorRepState.h"
#include "ProceduralStateComponent.generated.h"

class UTerrainPhysicsComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UProceduralStateComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    uint64 ProceduralPlacementSaveID;

    UPROPERTY(SaveGame, ReplicatedUsing = ApplyStateToOwner)
    FProceduralActorRepState repState;

    UPROPERTY(SaveGame)
    uint8 bRuntimeGenerated : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bApplyTintFromAttachParent : 1;

    UProceduralStateComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnTerrainPhysicsBuriedChanged(UTerrainPhysicsComponent *TerrainPhysics);

    UFUNCTION()
    void OnOwnerSpawnedInSlot();

    UFUNCTION()
    void ApplyStateToOwner();
};
