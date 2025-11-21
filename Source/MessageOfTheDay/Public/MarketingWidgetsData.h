#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MarketingWidgetsData.generated.h"

class UMarketingWidget;

UCLASS(Blueprintable)
class MESSAGEOFTHEDAY_API UMarketingWidgetsData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMarketingWidget*> MarketingWidgetsData;
    
    UMarketingWidgetsData();

};

