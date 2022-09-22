#pragma once
#include "CoreMinimal.h"
#include "ComponentRecord.h"
#include "ChildActorRecord.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "ActorRecord.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActorRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChildActorRecord> ChildActorRecords;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FComponentRecord> OwnedComponentRecords;
    
    UPROPERTY(EditAnywhere)
    uint32 ObjectIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RootTransform;
    
    ASTRO_API FActorRecord();
};

