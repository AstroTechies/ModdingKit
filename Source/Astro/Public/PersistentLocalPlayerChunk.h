#pragma once
#include "CoreMinimal.h"
#include "AstroSaveChunk.h"
#include "PersistentLocalPlayerChunk.generated.h"

class UPersistentLocalPlayerData;

USTRUCT(BlueprintType)
struct FPersistentLocalPlayerChunk : public FAstroSaveChunk {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPersistentLocalPlayerData* PlayerData;
    
public:
    ASTRO_API FPersistentLocalPlayerChunk();
};

