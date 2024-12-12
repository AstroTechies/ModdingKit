#pragma once
#include "CoreMinimal.h"
//#include "AstroServerInfo.h"
#include "AstroServerCommServerList.generated.h"

USTRUCT(BlueprintType)
struct FAstroServerCommServerList {
    GENERATED_BODY()
public:
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroServerInfo> ServerList;
    
    ASTRO_API FAstroServerCommServerList();
};

