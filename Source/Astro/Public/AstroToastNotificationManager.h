#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroNotificationToastAuthoringData.h"
#include "Engine/EngineTypes.h"
#include "AstroToastNotificationManager.generated.h"

class UAstroNotificationToastWidget;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroToastNotificationManager : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export)
    TArray<UAstroNotificationToastWidget *> LivingToastNotifications;

    UPROPERTY()
    TArray<FAstroNotificationToastAuthoringData> QueueOfToastNotifsToSpawn;

    UPROPERTY()
    FTimerHandle SpawnTimerHandle;

public:
    UAstroToastNotificationManager();

private:
    UFUNCTION()
    void HandleNotificationSpawnTimerTick();
};
