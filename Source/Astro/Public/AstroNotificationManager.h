#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LivingAstroNotification.h"
#include "NotificationSpawner.h"
#include "AstroNotificationManager.generated.h"

class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAstroNotificationManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<USceneComponent*, FNotificationSpawner> ActiveNotificationSpawners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLivingAstroNotification> LivingAstroNotifications;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 NotificationsDisabled: 1;
    
public:
    UAstroNotificationManager();
};

