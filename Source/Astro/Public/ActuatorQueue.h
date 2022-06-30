#pragma once
#include "CoreMinimal.h"
#include "ActuationRequest.h"
#include "UObject/Object.h"
#include "ActuatorQueue.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UActuatorQueue : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(SaveGame)
    TArray<FActuationRequest> PendingRequests;

public:
    UActuatorQueue();
    UFUNCTION(BlueprintPure)
    static float GetActuatorTickFrequency();

    UFUNCTION(BlueprintPure)
    static int32 GetActuatorDelayTickInterval();
};
