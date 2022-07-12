#pragma once
#include "CoreMinimal.h"
#include "SlotBehavior.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "SlotBehaviorBlueprint.generated.h"

class APhysicalItem;
class UPrimitiveComponent;

UCLASS(Blueprintable, EditInlineNew)
class USlotBehaviorBlueprint : public USlotBehavior {
    GENERATED_BODY()
public:
    USlotBehaviorBlueprint();
    UFUNCTION(BlueprintImplementableEvent)
    void OnParentStartedInWorld(APhysicalItem* Parent);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnParentPickedUpFromWorld(APhysicalItem* Parent);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnParentDroppedInWorld(APhysicalItem* Parent, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
};

