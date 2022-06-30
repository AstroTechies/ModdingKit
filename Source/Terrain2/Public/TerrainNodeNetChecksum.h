#pragma once
#include "CoreMinimal.h"
#include "TerrainNodeNetChecksum.generated.h"

USTRUCT(BlueprintType)
struct FTerrainNodeNetChecksum {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint64 NodeID;
    
    UPROPERTY()
    uint32 Checksum;
    
    TERRAIN2_API FTerrainNodeNetChecksum();
};

