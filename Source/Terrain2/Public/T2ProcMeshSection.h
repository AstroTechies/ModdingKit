#pragma once
#include "CoreMinimal.h"
#include "T2ProcMeshSection.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FT2ProcMeshSection {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UMaterialInterface* MaterialToAssignOnGT;
    
    TERRAIN2_API FT2ProcMeshSection();
};

