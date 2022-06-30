#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerNodeComponent.generated.h"

class UPowerComponent;

USTRUCT(BlueprintType)
struct FStreamingPowerNodeComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> ConnectionsInbound;
    
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> ConnectionsOutbound;
    
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> NeighboringNodesConnectedByMergedLinkNodes;
    
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> MergedNodeConnections;
    
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> VampireConnections;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UPowerComponent*> PowerGenerators;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UPowerComponent*> PowerConsumers;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UPowerComponent*> Batteries;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UPowerComponent*> Capacitors;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UPowerComponent*> AttachedPowerComponents;
    
private:
    UPROPERTY(SaveGame)
    FAstroDatumRef ParentMergedNode;
    
public:
    ASTRO_API FStreamingPowerNodeComponent();
};

