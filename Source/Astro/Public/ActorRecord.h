#pragma once
#include "CoreMinimal.h"
#include "ComponentRecord.h"
#include "ChildActorRecord.h"
#include "UObject/NoExportTypes.h"
#include "ActorRecord.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActorRecord {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    AActor* Actor;
    
    UPROPERTY()
    TArray<FChildActorRecord> ChildActorRecords;
    
    UPROPERTY()
    TArray<FComponentRecord> OwnedComponentRecords;
    
    UPROPERTY()
    uint32 ObjectIndex;
    
    UPROPERTY()
    FTransform RootTransform;
    
    ASTRO_API FActorRecord();
};

