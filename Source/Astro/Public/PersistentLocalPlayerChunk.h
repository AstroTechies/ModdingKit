#pragma once
#include "CoreMinimal.h"
#include "AstroSaveChunk.h"
#include "PersistentLocalPlayerChunk.generated.h"

class UPersistentLocalPlayerData;

USTRUCT()
struct FPersistentLocalPlayerChunk : public FAstroSaveChunk {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    UPersistentLocalPlayerData* PlayerData;
    
public:
    ASTRO_API FPersistentLocalPlayerChunk();
};

