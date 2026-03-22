#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuEntryWidgetDisplayData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAstroGameMenuEntryWidgetDisplayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LeftText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText RightText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsRightTextBold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* RightImage;
    
    ASTRO_API FAstroGameMenuEntryWidgetDisplayData();
};

