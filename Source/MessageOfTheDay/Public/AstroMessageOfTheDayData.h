#pragma once
#include "CoreMinimal.h"
//#include "SegmentedString.h"
#include "AstroMessageOfTheDayLocalizedContent.h"
#include "EAstroReleaseIDs.h"
#include "EMarketingWidgetType.h"
#include "AstroMessageOfTheDayData.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMessageOfTheDayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FAstroMessageOfTheDayLocalizedContent> Content;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FSegmentedString SegmentedAssociatedReleaseID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroReleaseIDs AssociatedReleaseID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMarketingWidgetType WidgetType;
    
    FAstroMessageOfTheDayData();
};

