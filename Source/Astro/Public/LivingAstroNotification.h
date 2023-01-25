#pragma once
#include "CoreMinimal.h"
#include "AstroNotificationTagAuthoringData.h"
#include "LivingAstroNotification.generated.h"

class UAstroNotificationTagWidget;
class USceneComponent;

USTRUCT(BlueprintType)
struct FLivingAstroNotification {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* OriginAnchor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroNotificationTagWidget* NotificationWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationTagAuthoringData AuthoringData;
    
    ASTRO_API FLivingAstroNotification();
};

