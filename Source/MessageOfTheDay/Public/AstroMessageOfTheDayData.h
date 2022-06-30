#pragma once
#include "CoreMinimal.h"
#include "EAstroMessageOfTheDayVersion.h"
#include "AstroMessageOfTheDayLocalizedContent.h"
#include "AstroMessageOfTheDayData.generated.h"

USTRUCT()
struct MESSAGEOFTHEDAY_API FAstroMessageOfTheDayData {
    GENERATED_BODY()
public:
    UPROPERTY()
    EAstroMessageOfTheDayVersion Version;
    
    UPROPERTY()
    TMap<FString, FAstroMessageOfTheDayLocalizedContent> Content;
    
    FAstroMessageOfTheDayData();
};

