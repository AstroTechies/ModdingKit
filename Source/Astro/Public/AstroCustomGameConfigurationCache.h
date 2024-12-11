#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayFabCGMConfigMetaDataList.h"
#include "AstroCustomGameSettings.h"
#include "FAstroCustomGameConfigurationCacheStatus.h"
#include "AstroCustomGameConfigurationCache.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomGameConfigurationCache {
    GENERATED_BODY()
public:
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    FAstroPlayFabCGMConfigMetaDataList MetaDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroCustomGameSettings> Configurations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAstroCustomGameConfigurationCacheStatus CacheStatus;
    
    ASTRO_API FAstroCustomGameConfigurationCache();
};

