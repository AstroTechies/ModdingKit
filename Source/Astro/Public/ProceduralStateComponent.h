#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralActorRepState.h"
#include "ProceduralStateComponent.generated.h"

class UTerrainPhysicsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProceduralStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint64 ProceduralPlacementSaveID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=ApplyStateToOwner, meta=(AllowPrivateAccess=true))
    FProceduralActorRepState repState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bRuntimeGenerated: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyTintFromAttachParent: 1;
    
    UProceduralStateComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void OnTerrainPhysicsBuriedChanged(UTerrainPhysicsComponent* TerrainPhysics);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerSpawnedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void ApplyStateToOwner();
    
};

