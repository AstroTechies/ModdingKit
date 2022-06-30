#pragma once
#include "CoreMinimal.h"
#include "AstroMessageOfTheDayLocalizedContent.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMessageOfTheDayLocalizedContent {
    GENERATED_BODY()
public:
    UPROPERTY()
    FText Title;
    
    UPROPERTY()
    FText LinkText;
    
    UPROPERTY()
    FString URL;
    
    UPROPERTY()
    FString BackgroundImageCDNKey;
    
    UPROPERTY()
    TArray<FText> Messages;
    
    FAstroMessageOfTheDayLocalizedContent();
};

