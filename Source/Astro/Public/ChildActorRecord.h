#pragma once
#include "CoreMinimal.h"
#include "ChildActorRecord.generated.h"

USTRUCT(BlueprintType)
struct FChildActorRecord {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint32 NameIndex;
    
    UPROPERTY()
    uint32 ActorIndex;
    
    ASTRO_API FChildActorRecord();
};

