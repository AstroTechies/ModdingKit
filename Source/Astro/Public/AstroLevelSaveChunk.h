#pragma once
#include "CoreMinimal.h"
#include "AstroSaveChunk.h"
#include "PlayerControllerRecord.h"
#include "AstroLevelSaveChunk.generated.h"

USTRUCT(BlueprintType)
struct FAstroLevelSaveChunk : public FAstroSaveChunk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlayerControllerRecord> PlayerControllerRecords;
    
    ASTRO_API FAstroLevelSaveChunk();
};

