#pragma once
#include "CoreMinimal.h"
#include "ProcExpValueType.generated.h"

USTRUCT(BlueprintType)
struct FProcExpValueType {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 primitiveType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsPointer: 1;
    
    TERRAIN2_API FProcExpValueType();
};

