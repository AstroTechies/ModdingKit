#pragma once
#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "AstroReplicationGraph.generated.h"

class UAstroReplicationGraphNode_GridSpatialization3D;
class UReplicationGraphNode_ActorList;

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraph : public UReplicationGraph
{
    GENERATED_BODY()
public:
    UPROPERTY()
    UAstroReplicationGraphNode_GridSpatialization3D *GridNodes[2];

    UPROPERTY()
    UReplicationGraphNode_ActorList *AlwaysRelevantNode;

    UAstroReplicationGraph();
};
