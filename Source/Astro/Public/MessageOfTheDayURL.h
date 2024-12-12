#pragma once
#include "CoreMinimal.h"
#include "MessageOfTheDayURL.generated.h"

USTRUCT(BlueprintType)
struct FMessageOfTheDayURL {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CultureCode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FriendlyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString URL;
    
    ASTRO_API FMessageOfTheDayURL();
};

