#pragma once
#include "CoreMinimal.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "OnUnlockNotificationCompleteDelegate.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "AstroUnlockNotificationManager.generated.h"

class UAstroNotificationUnlockWidget;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroUnlockNotificationManager : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnUnlockNotificationComplete UnlockNotificationComplete;

private:
    UPROPERTY(Export)
    TArray<UAstroNotificationUnlockWidget *> LivingUnlockNotifications;

    UPROPERTY()
    TArray<FAstroNotificationUnlockAuthoringData> QueueOfUnlockNotifsToSpawn;

    UPROPERTY()
    FTimerHandle SpawnTimerHandle;

public:
    UAstroUnlockNotificationManager();

private:
    UFUNCTION()
    void HandleNotificationSpawnTimerTick();
};
