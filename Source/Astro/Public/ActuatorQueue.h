#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActuationRequest.h"
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

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetActuatorTickFrequency();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetActuatorDelayTickInterval();
    
};

