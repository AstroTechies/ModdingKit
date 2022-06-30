#pragma once
#include "CoreMinimal.h"
#include "EPlayerPlatform.h"
#include "PlayerNicknameAndPlatform.generated.h"

USTRUCT(BlueprintType)
struct FPlayerNicknameAndPlatform {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FString PlayerNickname;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EPlayerPlatform Platform;
    
    ASTRO_API FPlayerNicknameAndPlatform();
};

