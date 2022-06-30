#pragma once
#include "CoreMinimal.h"
#include "AstroNotificationTagAuthoringData.h"
#include "LivingAstroNotification.generated.h"

class USceneComponent;
class UAstroNotificationTagWidget;

USTRUCT(BlueprintType)
struct FLivingAstroNotification {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    USceneComponent* OriginAnchor;
    
    UPROPERTY(Export)
    UAstroNotificationTagWidget* NotificationWidget;
    
    UPROPERTY()
    FAstroNotificationTagAuthoringData AuthoringData;
    
    ASTRO_API FLivingAstroNotification();
};

