#pragma once
#include "CoreMinimal.h"
#include "AstroMessageOfTheDayLocalizedContent.h"
#include "EAstroMessageOfTheDayVersion.h"
#include "AstroMessageOfTheDayData.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMessageOfTheDayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroMessageOfTheDayVersion Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FAstroMessageOfTheDayLocalizedContent> Content;
    
    FAstroMessageOfTheDayData();
};

