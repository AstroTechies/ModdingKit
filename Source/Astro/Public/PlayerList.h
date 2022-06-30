#pragma once
#include "CoreMinimal.h"
#include "PlayerInfo.h"
#include "PlayerList.generated.h"

USTRUCT(BlueprintType)
struct FPlayerList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FPlayerInfo> PlayerInfo;
    
    ASTRO_API FPlayerList();
};

