#pragma once
#include "CoreMinimal.h"
#include "AstroMessageOfTheDayLocalizedContent.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMessageOfTheDayLocalizedContent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LinkText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString URL;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BackgroundImageCDNKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> Messages;
    
    FAstroMessageOfTheDayLocalizedContent();
};

