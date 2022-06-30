#pragma once
#include "CoreMinimal.h"
#include "ProcExpValueType.generated.h"

USTRUCT()
struct FProcExpValueType {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint32 primitiveType;
    
    UPROPERTY()
    uint8 bIsPointer: 1;
    
    TERRAIN2_API FProcExpValueType();
};

