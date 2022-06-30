#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ENotificationTagPresentationDirection.h"
#include "AstroNotificationTagWidgetDisplayData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAstroNotificationTagWidgetDisplayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TagText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENotificationTagPresentationDirection PresentationDirection;
    
    ASTRO_API FAstroNotificationTagWidgetDisplayData();
};

