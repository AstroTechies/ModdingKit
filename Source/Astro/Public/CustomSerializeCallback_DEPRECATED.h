#pragma once
#include "CoreMinimal.h"
#include "Callback_DEPRECATED.h"
#include "CustomSerializeCallback_DEPRECATED.generated.h"

USTRUCT(BlueprintType)
struct FCustomSerializeCallback_DEPRECATED {
    GENERATED_BODY()
public:
    UPROPERTY()
    FCallback_DEPRECATED Callback;
    
    UPROPERTY()
    uint32 ArchivePosition;
    
    UPROPERTY()
    uint16 ArchiveVersion;
    
    ASTRO_API FCustomSerializeCallback_DEPRECATED();
};

