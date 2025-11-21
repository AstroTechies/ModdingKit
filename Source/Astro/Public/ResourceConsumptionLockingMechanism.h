#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "Templates/SubclassOf.h"
#include "ResourceConsumptionLockingMechanism.generated.h"

class AActor;
class APawn;
class APhysicalItem;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API UResourceConsumptionLockingMechanism : public ULockingMechanism {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ConsumedResourceUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    APhysicalItem* ItemBeingConsumed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APawn> ItemConsumptionInstigator;
    
public:
    UResourceConsumptionLockingMechanism();

    UFUNCTION(BlueprintCallable)
    void OnItemSetInResourceConsumptionSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemBeingConsumedDrained(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void OnItemBeingConsumedDestroyed(AActor* DestroyedActor);
    
};

