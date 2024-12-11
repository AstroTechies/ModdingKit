#pragma once
#include "CoreMinimal.h"
#include "GameEntry.generated.h"

USTRUCT(BlueprintType)
struct FGameEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Date;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHasBeenFlaggedAsCreativeModeSave: 1;
    
    ASTRO_API FGameEntry();
};

