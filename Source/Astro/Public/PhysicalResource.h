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
    
    UFUNCTION(BlueprintCallable)
    void PostDrained();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrained();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFullness();
    
};

