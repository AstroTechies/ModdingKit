#pragma once
#include "CoreMinimal.h"
#include "AstroFoliageDestructionRequest.h"
#include "UObject/Object.h"
#include "AstroFoliageDestructionManager.generated.h"

class UWorld;
class UAstroGameInstance;
class UCollectibleHandler;
class UResourceExtractorManager;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroFoliageDestructionManager : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    TArray<FAstroFoliageDestructionRequest> Requests;

    UPROPERTY(Transient)
    UWorld *WorldCache;

    UPROPERTY(Transient)
    UAstroGameInstance *AstroGameInstanceCache;

    UPROPERTY(Transient)
    UCollectibleHandler *CollectibleHandlerCache;

    UPROPERTY(Transient)
    UResourceExtractorManager *ExtractorManagerCache;

public:
    UAstroFoliageDestructionManager();
};
