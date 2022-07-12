#pragma once
#include "CoreMinimal.h"
#include "InputReference.generated.h"

USTRUCT(BlueprintType)
struct FInputReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputName;
    
    UPROPERTY(EditAnywhere)
    uint8 bIsAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    ASTRO_API FInputReference();
};

