#pragma once
#include "CoreMinimal.h"
#include "AstroMarketingWidgetContentData.h"
#include "AstroMarketingWidgetsData.generated.h"

USTRUCT(BlueprintType)
struct MESSAGEOFTHEDAY_API FAstroMarketingWidgetsData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroMarketingWidgetContentData> MarketingWidgetsContent;
    
    FAstroMarketingWidgetsData();
};

