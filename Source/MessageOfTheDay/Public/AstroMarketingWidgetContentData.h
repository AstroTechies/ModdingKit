#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayerSegment.h"
#include "EAstroReleaseIDs.h"
#include "EMarketingWidgetType.h"
#include "AstroMarketingWidgetContentData.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMarketingWidgetContentData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMarketingWidgetType WidgetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroReleaseIDs AssociatedReleaseID;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroPlayerSegment> Segments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString URL;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BackgroundImageCDNKey;
    
    FAstroMarketingWidgetContentData();
};

