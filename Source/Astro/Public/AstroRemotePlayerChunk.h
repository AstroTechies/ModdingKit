#pragma once
#include "CoreMinimal.h"
#include "AstroSaveChunk.h"
#include "AstroRemotePlayerChunk.generated.h"

class APlayerController;

USTRUCT(BlueprintType)
struct FAstroRemotePlayerChunk : public FAstroSaveChunk {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    APlayerController* Controller;
    
public:
    ASTRO_API FAstroRemotePlayerChunk();
};

