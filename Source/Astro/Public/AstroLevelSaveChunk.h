#pragma once
#include "CoreMinimal.h"
#include "AstroSaveChunk.h"
#include "PlayerControllerRecord.h"
#include "AstroLevelSaveChunk.generated.h"

USTRUCT(BlueprintType)
struct FAstroLevelSaveChunk : public FAstroSaveChunk {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FString Level;
    
    UPROPERTY(Transient)
    TArray<FPlayerControllerRecord> PlayerControllerRecords;
    
    ASTRO_API FAstroLevelSaveChunk();
};

