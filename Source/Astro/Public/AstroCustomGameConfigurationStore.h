#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayFabCGMConfigMetaDataList.h"
#include "AstroCustomGameSettings.h"
#include "AstroCustomGameConfigurationStore.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomGameConfigurationStore {
    GENERATED_BODY()
public:
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
//    FAstroPlayFabCGMConfigMetaDataList MetaDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroCustomGameSettings> Configurations;
    
    ASTRO_API FAstroCustomGameConfigurationStore();
};

