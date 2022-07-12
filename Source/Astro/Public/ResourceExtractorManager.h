#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ResourceExtractorState.h"
#include "ExtractorGroupResourceCache.h"
#include "EResourceExtractorActivationFlags.h"
#include "ResourceExtractorManager.generated.h"

class AResourceExtractor;

UCLASS(Blueprintable)
class UResourceExtractorManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FResourceExtractorState> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FExtractorGroupResourceCache> Caches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> ReconcileOperationQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> AddToCacheOperationQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> RemoveFromOperationQueue;
    
    UPROPERTY(EditAnywhere, SaveGame)
    uint32 GroupIDCounter;
    
public:
    UResourceExtractorManager();
private:
    UFUNCTION()
    void OnHammerDroppped(AResourceExtractor* Extractor);
    
    UFUNCTION()
    void OnClientVisualStateChanged(AResourceExtractor* Extractor);
    
    UFUNCTION()
    void OnClientAnimProgressChanged(AResourceExtractor* Extractor);
    
    UFUNCTION()
    void OnBillowsBegin(AResourceExtractor* Extractor);
    
    UFUNCTION()
    void OnActivationStatusChanged(AResourceExtractor* Extractor, EResourceExtractorActivationFlags ChangedFlag, bool IsActive);
    
};

