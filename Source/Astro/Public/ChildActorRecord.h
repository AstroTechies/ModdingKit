#pragma once
#include "CoreMinimal.h"
#include "ChildActorRecord.generated.h"

USTRUCT(BlueprintType)
struct FChildActorRecord {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NameIndex;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ActorIndex;
    
    ASTRO_API FChildActorRecord();
};

