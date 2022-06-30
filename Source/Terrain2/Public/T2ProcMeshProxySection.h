#pragma once
#include "CoreMinimal.h"
#include "T2ProcMeshProxySection.generated.h"

class UMaterialInterface;

USTRUCT()
struct FT2ProcMeshProxySection {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UMaterialInterface* Material;
    
    TERRAIN2_API FT2ProcMeshProxySection();
};

