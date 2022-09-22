#pragma once
#include "CoreMinimal.h"
#include "AstroFoliageDestructionRequest.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AstroFoliageDestructionManager.generated.h"

class UCollectibleHandler;
class UWorld;
class UAstroGameInstance;
class UResourceExtractorManager;

UCLASS(Blueprintable)
class ASTRO_API UAstroFoliageDestructionManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroFoliageDestructionRequest> Requests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* WorldCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroGameInstance* AstroGameInstanceCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCollectibleHandler* CollectibleHandlerCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UResourceExtractorManager* ExtractorManagerCache;
    
public:
    UAstroFoliageDestructionManager();
};

