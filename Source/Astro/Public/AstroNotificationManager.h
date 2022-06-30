#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NotificationSpawner.h"
#include "LivingAstroNotification.h"
#include "AstroNotificationManager.generated.h"

class USceneComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UAstroNotificationManager : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    TMap<USceneComponent *, FNotificationSpawner> ActiveNotificationSpawners;

    UPROPERTY(Transient)
    TArray<FLivingAstroNotification> LivingAstroNotifications;

private:
    UPROPERTY(Transient)
    uint8 NotificationsDisabled : 1;

public:
    UAstroNotificationManager();
};
