#pragma once
#include "CoreMinimal.h"
#include "ActorRecord.h"
#include "ObjectSaveRecord.h"
#include "AstroSaveChunk.generated.h"

class UAstroSaveCustomArchiveProxy;
class ULevel;

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

