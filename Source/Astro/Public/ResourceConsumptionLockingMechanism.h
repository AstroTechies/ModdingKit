#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "ResourceConsumptionLockingMechanism.generated.h"

class APhysicalItem;
class APawn;
class AActor;

UCLASS(Blueprintable)
class ASTRO_API UResourceConsumptionLockingMechanism : public ULockingMechanism {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ConsumedResourceUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    APhysicalItem* ItemBeingConsumed;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TWeakObjectPtr<APawn> ItemConsumptionInstigator;
    
public:
    UResourceConsumptionLockingMechanism();
    UFUNCTION()
    void OnItemSetInResourceConsumptionSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void OnItemBeingConsumedDrained();
    
    UFUNCTION()
    void OnItemBeingConsumedDestroyed(AActor* DestroyedActor);
    
};

