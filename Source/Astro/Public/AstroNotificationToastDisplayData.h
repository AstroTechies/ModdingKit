#pragma once
#include "CoreMinimal.h"
#include "EAstroColor.h"
#include "AstroNotificationToastDisplayData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAstroNotificationToastDisplayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroColor BadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ToastTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ToastText;
    
    ASTRO_API FAstroNotificationToastDisplayData();
};

