#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PSActivitiesManager.generated.h"

UCLASS(Blueprintable)
class UPSActivitiesManager : public UObject {
    GENERATED_BODY()
public:
    UPSActivitiesManager();

    UFUNCTION(BlueprintCallable)
    void SetStartActivity(const FName ActivityID, const bool ActivityAvaliblity);
    
    UFUNCTION(BlueprintCallable)
    void SetFailedActivity(const FName ActivityID);
    
    UFUNCTION(BlueprintCallable)
    void SetCompleteActivity(const FName ActivityID);
    
    UFUNCTION(BlueprintCallable)
    void SetCancelActivity(const FName ActivityID);
    
    UFUNCTION(BlueprintCallable)
    void SetActivityAvailability(const FName& ActivityID, const bool& ActivityAvalibility);
    
};

