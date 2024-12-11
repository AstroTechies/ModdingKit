#pragma once
#include "CoreMinimal.h"
//#include "SegmentedString.h"
#include "AstroMessageOfTheDayLocalizedContent.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMessageOfTheDayLocalizedContent {
    GENERATED_BODY()
public:
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FSegmentedString Title;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FSegmentedString LinkText;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FSegmentedString URL;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FSegmentedString BackgroundImageCDNKey;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FSegmentedString> Messages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> FullscreenSegments;
    
    FAstroMessageOfTheDayLocalizedContent();
};

