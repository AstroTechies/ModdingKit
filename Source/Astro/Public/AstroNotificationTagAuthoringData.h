#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ENotificationTagPresentationDirection.h"
#include "AstroNotificationTagAuthoringData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAstroNotificationTagAuthoringData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseCustomBadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor CustomBadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SoundEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TagText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENotificationTagPresentationDirection PresentationDirection;
    
    ASTRO_API FAstroNotificationTagAuthoringData();
};

