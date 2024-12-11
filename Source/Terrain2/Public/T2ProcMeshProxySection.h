#pragma once
#include "CoreMinimal.h"
#include "T2ProcMeshProxySection.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FT2ProcMeshProxySection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    TERRAIN2_API FT2ProcMeshProxySection();
};

