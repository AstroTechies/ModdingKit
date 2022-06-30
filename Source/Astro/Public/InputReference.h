#pragma once
#include "CoreMinimal.h"
#include "InputReference.generated.h"

USTRUCT(BlueprintType)
struct FInputReference {
    GENERATED_BODY()
public:
    UPROPERTY()
    FName InputName;
    
    UPROPERTY()
    uint8 bIsAxis;
    
    UPROPERTY()
    float Scale;
    
    ASTRO_API FInputReference();
};

FORCEINLINE uint32 GetTypeHash(const FInputReference& InputReference) {
    return 0;
}
