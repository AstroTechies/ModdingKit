#pragma once
#include "CoreMinimal.h"
#include "ExplicitOxygenConnections.generated.h"

class ASlotConnection;

USTRUCT(BlueprintType)
struct FExplicitOxygenConnections {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<ASlotConnection*> Connections;
    
    UPROPERTY(SaveGame)
    TArray<int32> RailConnections;
    
    ASTRO_API FExplicitOxygenConnections();
};

