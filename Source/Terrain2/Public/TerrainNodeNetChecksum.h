#pragma once
#include "CoreMinimal.h"
#include "TerrainNodeNetChecksum.generated.h"

USTRUCT(BlueprintType)
struct FTerrainNodeNetChecksum {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint64 NodeID;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 Checksum;
    
    TERRAIN2_API FTerrainNodeNetChecksum();
};

