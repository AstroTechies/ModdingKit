#pragma once
#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "AstroReplicationGraphNode_AlwaysRelevant_ForConnection.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAstroReplicationGraphNode_AlwaysRelevant_ForConnection : public UReplicationGraphNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LastPawn;
    
public:
    UAstroReplicationGraphNode_AlwaysRelevant_ForConnection();
};

