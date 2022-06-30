#pragma once
#include "CoreMinimal.h"
#include "GameEntry.h"
#include "GameList.generated.h"

USTRUCT(BlueprintType)
struct FGameList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FString ActiveSaveName;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FGameEntry> GameList;
    
    ASTRO_API FGameList();
};

