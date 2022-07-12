#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ProceduralActorRepState.h"
#include "ProceduralStateComponent.generated.h"

class UTerrainPhysicsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProceduralStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    uint64 ProceduralPlacementSaveID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=ApplyStateToOwner, meta=(AllowPrivateAccess=true))
    FProceduralActorRepState repState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bRuntimeGenerated: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyTintFromAttachParent: 1;
    
    UProceduralStateComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION()
    void OnTerrainPhysicsBuriedChanged(UTerrainPhysicsComponent* TerrainPhysics);
    
    UFUNCTION()
    void OnOwnerSpawnedInSlot();
    
    UFUNCTION()
    void ApplyStateToOwner();
    
};

