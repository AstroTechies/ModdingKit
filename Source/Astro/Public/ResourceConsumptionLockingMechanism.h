#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "ResourceConsumptionLockingMechanism.generated.h"

class AActor;
class APhysicalItem;
class APawn;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UResourceConsumptionLockingMechanism : public ULockingMechanism
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    int32 ConsumedResourceUnits;

    UPROPERTY(SaveGame)
    APhysicalItem *ItemBeingConsumed;

    UPROPERTY(SaveGame)
    TWeakObjectPtr<APawn> ItemConsumptionInstigator;

public:
    UResourceConsumptionLockingMechanism();
    UFUNCTION()
    void OnItemSetInResourceConsumptionSlot(APhysicalItem *Item);

    UFUNCTION()
    void OnItemBeingConsumedDrained();

    UFUNCTION()
    void OnItemBeingConsumedDestroyed(AActor *DestroyedActor);
};
