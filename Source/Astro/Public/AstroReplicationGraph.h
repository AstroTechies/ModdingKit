#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=ReplicationGraph -ObjectName=ReplicationGraph -FallbackName=ReplicationGraph
#include "ReplicationGraph.h"
#include "AstroReplicationGraph.generated.h"

class UAstroReplicationGraphNode_GridSpatialization3D;
class UReplicationGraphNode_ActorList;

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraph : public UReplicationGraph {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UAstroReplicationGraphNode_GridSpatialization3D* GridNodes[2];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReplicationGraphNode_ActorList* AlwaysRelevantNode;
    
    UAstroReplicationGraph();
};

