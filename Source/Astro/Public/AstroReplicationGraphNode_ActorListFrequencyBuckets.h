#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=ReplicationGraph -ObjectName=ReplicationGraphNode -FallbackName=ReplicationGraphNode
#include "ReplicationGraph.h"
#include "AstroReplicationGraphNode_ActorListFrequencyBuckets.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraphNode_ActorListFrequencyBuckets : public UReplicationGraphNode {
    GENERATED_BODY()
public:
    UAstroReplicationGraphNode_ActorListFrequencyBuckets();
};

