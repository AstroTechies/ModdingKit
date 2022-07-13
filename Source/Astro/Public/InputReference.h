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
    
	friend uint32 GetTypeHash(const FInputReference& Other) {
		return 0;
	}

    ASTRO_API FInputReference();
};

