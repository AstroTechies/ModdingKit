#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "AstroNotificationToastAuthoringData.h"
#include "AstroToastNotificationManager.generated.h"

class UAstroNotificationToastWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroToastNotificationManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UAstroNotificationToastWidget*> LivingToastNotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroNotificationToastAuthoringData> QueueOfToastNotifsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle SpawnTimerHandle;
    
public:
    UAstroToastNotificationManager();
private:
    UFUNCTION()
    void HandleNotificationSpawnTimerTick();
    
};

