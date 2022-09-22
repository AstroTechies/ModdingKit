#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "OnUnlockNotificationCompleteDelegate.h"
#include "AstroNotificationUnlockAuthoringData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "AstroUnlockNotificationManager.generated.h"

class UAstroNotificationUnlockWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroUnlockNotificationManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUnlockNotificationComplete UnlockNotificationComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UAstroNotificationUnlockWidget*> LivingUnlockNotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroNotificationUnlockAuthoringData> QueueOfUnlockNotifsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle SpawnTimerHandle;
    
public:
    UAstroUnlockNotificationManager();
private:
    UFUNCTION()
    void HandleNotificationSpawnTimerTick();
    
};

