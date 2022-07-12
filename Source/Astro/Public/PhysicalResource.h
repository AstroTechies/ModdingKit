#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "PhysicalResource.generated.h"

UCLASS(Blueprintable)
class ASTRO_API APhysicalResource : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DestroyOnDrain;
    
    APhysicalResource();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetView();
    
    UFUNCTION()
    void PostDrained();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDrained();
    
    UFUNCTION(BlueprintPure)
    bool IsFull();
    
    UFUNCTION(BlueprintPure)
    bool IsEmpty();
    
    UFUNCTION(BlueprintPure)
    float GetFullness();
    
};

