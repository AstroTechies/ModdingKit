#pragma once
#include "CoreMinimal.h"
#include "Callback_DEPRECATED.h"
#include "CustomSerializeCallback_DEPRECATED.generated.h"

USTRUCT(BlueprintType)
struct FCustomSerializeCallback_DEPRECATED {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCallback_DEPRECATED Callback;
    
    UPROPERTY(EditAnywhere)
    uint32 ArchivePosition;
    
    UPROPERTY(EditAnywhere)
    uint16 ArchiveVersion;
    
    ASTRO_API FCustomSerializeCallback_DEPRECATED();
};

