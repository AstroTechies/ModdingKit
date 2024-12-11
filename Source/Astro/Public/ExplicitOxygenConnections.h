#pragma once
#include "CoreMinimal.h"
#include "ExplicitOxygenConnections.generated.h"

class ASlotConnection;

USTRUCT(BlueprintType)
struct FExplicitOxygenConnections {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASlotConnection*> Connections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> RailConnections;
    
    ASTRO_API FExplicitOxygenConnections();
};

