#pragma once
#include "CoreMinimal.h"
#include "InputKeyToIconMappingEntry.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FInputKeyToIconMappingEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* AlternateResourceObjectHold;
    
    ASTRO_API FInputKeyToIconMappingEntry();
};

