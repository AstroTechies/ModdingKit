#pragma once
#include "CoreMinimal.h"
#include "AstroReplicationGraphNode_ActorListFrequencyBuckets.h"
#include "AstroReplicationGraphNode_GridCell.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraphNode_GridCell : public UAstroReplicationGraphNode_ActorListFrequencyBuckets {
    GENERATED_BODY()
public:
    UAstroReplicationGraphNode_GridCell();
};

