#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "OnUnlockNotificationCompleteDelegate.h"
#include "AstroUnlockNotificationManager.generated.h"

class UAstroNotificationUnlockWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroUnlockNotificationManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUnlockNotificationComplete UnlockNotificationComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAstroNotificationUnlockWidget*> LivingUnlockNotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroNotificationUnlockAuthoringData> QueueOfUnlockNotifsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle SpawnTimerHandle;
    
public:
    UAstroUnlockNotificationManager();

private:
    UFUNCTION(BlueprintCallable)
    void HandleNotificationSpawnTimerTick();
    
};

