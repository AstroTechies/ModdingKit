#pragma once
#include "CoreMinimal.h"
#include "ActuationRequest.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ActuatorQueue.generated.h"

UCLASS(Blueprintable)
class UActuatorQueue : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActuationRequest> PendingRequests;
    
public:
    UActuatorQueue();
    UFUNCTION(BlueprintPure)
    static float GetActuatorTickFrequency();
    
    UFUNCTION(BlueprintPure)
    static int32 GetActuatorDelayTickInterval();
    
};

