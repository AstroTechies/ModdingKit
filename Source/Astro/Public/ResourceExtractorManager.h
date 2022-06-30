#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ResourceExtractorState.h"
#include "ExtractorGroupResourceCache.h"
#include "EResourceExtractorActivationFlags.h"
#include "ResourceExtractorManager.generated.h"

class AResourceExtractor;

UCLASS(Blueprintable, Blueprintable)
class UResourceExtractorManager : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(SaveGame)
    TArray<FResourceExtractorState> States;

    UPROPERTY(SaveGame)
    TArray<FExtractorGroupResourceCache> Caches;

    UPROPERTY(SaveGame)
    TArray<int32> ReconcileOperationQueue;

    UPROPERTY(SaveGame)
    TArray<int32> AddToCacheOperationQueue;

    UPROPERTY(SaveGame)
    TArray<int32> RemoveFromOperationQueue;

    UPROPERTY(SaveGame)
    uint32 GroupIDCounter;

public:
    UResourceExtractorManager();

private:
    UFUNCTION()
    void OnHammerDroppped(AResourceExtractor *Extractor);

    UFUNCTION()
    void OnClientVisualStateChanged(AResourceExtractor *Extractor);

    UFUNCTION()
    void OnClientAnimProgressChanged(AResourceExtractor *Extractor);

    UFUNCTION()
    void OnBillowsBegin(AResourceExtractor *Extractor);

    UFUNCTION()
    void OnActivationStatusChanged(AResourceExtractor *Extractor, EResourceExtractorActivationFlags ChangedFlag, bool IsActive);
};
