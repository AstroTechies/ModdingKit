#pragma once
#include "CoreMinimal.h"
#include "ObjectSaveRecord.h"
#include "ActorRecord.h"
#include "AstroSaveChunk.generated.h"

class ULevel;
class UAstroSaveCustomArchiveProxy;

USTRUCT()
struct FAstroSaveChunk {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TArray<FObjectSaveRecord> ObjectRecords;
    
    UPROPERTY(Transient)
    TArray<FActorRecord> ActorRecords;
    
protected:
    UPROPERTY(Transient)
    ULevel* CurrentLevel;
    
    UPROPERTY(Transient)
    UAstroSaveCustomArchiveProxy* CustomSaveArchiveProxy;
    
public:
    ASTRO_API FAstroSaveChunk();
};

