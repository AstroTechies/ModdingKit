#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "SlottedItemRequirementRuntimeState.h"
#include "SlottedItemLockingMechanism.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API USlottedItemLockingMechanism : public ULockingMechanism
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    TArray<FSlottedItemRequirementRuntimeState> SlotRequirementsRuntimeState;

public:
    USlottedItemLockingMechanism();
    UFUNCTION()
    void OnItemSetInRelevantSlot(APhysicalItem *Item);

    UFUNCTION()
    void OnItemReleasedFromRelevantSlot(APhysicalItem *Item);
};
