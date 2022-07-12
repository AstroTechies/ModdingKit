#pragma once
#include "CoreMinimal.h"
#include "ObjectSaveRecord.h"
#include "ActorRecord.h"
#include "AstroSaveChunk.generated.h"

class ULevel;
class UAstroSaveCustomArchiveProxy;

USTRUCT(BlueprintType)
struct FAstroSaveChunk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FObjectSaveRecord> ObjectRecords;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FActorRecord> ActorRecords;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevel* CurrentLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroSaveCustomArchiveProxy* CustomSaveArchiveProxy;
    
public:
    ASTRO_API FAstroSaveChunk();
};

