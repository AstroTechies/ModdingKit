#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "PhysicalResource.generated.h"

class UItemType;

UCLASS(Blueprintable)
class ASTRO_API APhysicalResource : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DestroyOnDrain;
    
    APhysicalResource(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetView();
    
    UFUNCTION(BlueprintCallable)
    void PostDrained();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrained(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFullness();
    
};

