#pragma once
#include "CoreMinimal.h"
#include "NotificationToSpawnPayload.h"
#include "NotificationSpawner.generated.h"

USTRUCT(BlueprintType)
struct FNotificationSpawner {
    GENERATED_BODY()
public:
    UPROPERTY()
    TArray<FNotificationToSpawnPayload> NotificationsToSpawn;
    
    ASTRO_API FNotificationSpawner();
};

