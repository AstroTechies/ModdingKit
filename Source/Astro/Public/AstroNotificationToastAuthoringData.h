#pragma once
#include "CoreMinimal.h"
#include "EAstroColor.h"
#include "AstroNotificationToastAuthoringData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAstroNotificationToastAuthoringData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroColor CustomBadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ToastTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ToastText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SoundEvent;
    
    ASTRO_API FAstroNotificationToastAuthoringData();
};

