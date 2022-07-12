#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=ReplicationGraph -ObjectName=ReplicationGraphNode -FallbackName=ReplicationGraphNode
#include "ReplicationGraph.h"
#include "AstroReplicationGraphNode_GridSpatialization3D.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraphNode_GridSpatialization3D : public UReplicationGraphNode {
    GENERATED_BODY()
public:
    UAstroReplicationGraphNode_GridSpatialization3D();
};

