#pragma once
#include "CoreMinimal.h"
#include "ComponentRecord.generated.h"

USTRUCT(BlueprintType)
struct FComponentRecord {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NameIndex;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ObjectIndex;
    
    ASTRO_API FComponentRecord();
};

