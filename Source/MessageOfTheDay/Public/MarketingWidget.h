#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayerSegment.h"
#include "UObject/Object.h"
#include "EAstroMessageOfTheDayVersion.h"
#include "EAstroReleaseIDs.h"
#include "EMarketingWidgetType.h"
#include "MarketingWidget.generated.h"

UCLASS(Blueprintable)
class MESSAGEOFTHEDAY_API UMarketingWidget : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroMessageOfTheDayVersion Version;
    
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
    
    UMarketingWidget();

};

