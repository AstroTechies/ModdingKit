#pragma once
#include "CoreMinimal.h"
#include "ChildActorRecord.generated.h"

USTRUCT(BlueprintType)
struct FChildActorRecord {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint32 NameIndex;
    
    UPROPERTY(EditAnywhere)
    uint32 ActorIndex;
    
    ASTRO_API FChildActorRecord();
};

