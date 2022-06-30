#pragma once
#include "CoreMinimal.h"
#include "SlotBehavior.h"
#include "UObject/NoExportTypes.h"
#include "SlotBehaviorBlueprint.generated.h"

class APhysicalItem;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable, EditInlineNew)
class USlotBehaviorBlueprint : public USlotBehavior
{
    GENERATED_BODY()
public:
    USlotBehaviorBlueprint();
    UFUNCTION(BlueprintImplementableEvent)
    void OnParentStartedInWorld(APhysicalItem *Parent);

    UFUNCTION(BlueprintImplementableEvent)
    void OnParentPickedUpFromWorld(APhysicalItem *Parent);

    UFUNCTION(BlueprintImplementableEvent)
    void OnParentDroppedInWorld(APhysicalItem *Parent, UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);
};
