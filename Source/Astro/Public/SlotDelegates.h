#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SignalDelegate.h"
#include "SlotDelegateDelegate.h"
#include "ItemDelegateDelegate.h"
#include "SlotConnectionDelegateDelegate.h"
#include "ActuatorEventDelegateDelegate.h"
#include "SlotDelegates.generated.h"

UCLASS(Blueprintable, Blueprintable)
class USlotDelegates : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FItemDelegate OnSetItem;

    UPROPERTY(BlueprintAssignable)
    FItemDelegate OnReleaseItem;

    UPROPERTY(BlueprintAssignable)
    FItemDelegate OnEmplaceItem;

    UPROPERTY(BlueprintAssignable)
    FItemDelegate OnUnemplaceItem;

    UPROPERTY(BlueprintAssignable)
    FItemDelegate OnDestroyItem;

    UPROPERTY(BlueprintAssignable)
    FSlotDelegate OnExternalConnectionClicked;

    UPROPERTY(BlueprintAssignable)
    FSlotConnectionDelegate OnConnectionBuild;

    UPROPERTY(BlueprintAssignable)
    FSlotConnectionDelegate OnConnectionBuilding;

    UPROPERTY(BlueprintAssignable)
    FSlotConnectionDelegate OnConnectionComplete;

    UPROPERTY(BlueprintAssignable)
    FSlotConnectionDelegate OnConnectionPostComplete;

    UPROPERTY(BlueprintAssignable)
    FSlotConnectionDelegate OnConnectionRemove;

    UPROPERTY(BlueprintAssignable)
    FSlotConnectionDelegate OnConnectionDestroy;

    UPROPERTY(BlueprintAssignable)
    FSignal OnIndicatorClick;

    UPROPERTY(BlueprintAssignable)
    FActuatorEventDelegate OnActuatedThroughSlot;

    UPROPERTY(BlueprintAssignable)
    FSlotDelegate OnTracePrimitiveCreated;

    UPROPERTY(BlueprintAssignable)
    FSlotDelegate OnTracePrimitiveDestroyed;

    USlotDelegates();
};
