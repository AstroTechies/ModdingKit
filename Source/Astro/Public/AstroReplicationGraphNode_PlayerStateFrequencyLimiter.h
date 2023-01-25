#pragma once
#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "AstroReplicationGraphNode_PlayerStateFrequencyLimiter.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraphNode_PlayerStateFrequencyLimiter : public UReplicationGraphNode {
    GENERATED_BODY()
public:
    UAstroReplicationGraphNode_PlayerStateFrequencyLimiter();
};

