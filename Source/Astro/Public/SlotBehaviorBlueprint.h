#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "SlotBehavior.h"
#include "SlotBehaviorBlueprint.generated.h"

class APhysicalItem;
class UPrimitiveComponent;

UCLASS(Blueprintable, EditInlineNew)
class USlotBehaviorBlueprint : public USlotBehavior {
    GENERATED_BODY()
public:
    USlotBehaviorBlueprint();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnParentStartedInWorld(APhysicalItem* Parent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnParentPickedUpFromWorld(APhysicalItem* Parent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnParentDroppedInWorld(APhysicalItem* Parent, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
};

