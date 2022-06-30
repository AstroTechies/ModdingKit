#pragma once
#include "CoreMinimal.h"
#include "ECableTutorialStep.h"
#include "Components/ActorComponent.h"
#include "TooltipWidgetDisplayData.h"
#include "SignalDelegate.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "CableTutorialComponent.generated.h"

class UTooltipComponent;
class APhysicalItem;
class USlotsComponent;
class UPrimitiveComponent;
class ASlotConnection;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCableTutorialComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPushCableSlotTooltip, UTooltipComponent *, TooltipComponent, ECableTutorialStep, InteractionStep);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPopCableSlotTooltip, UTooltipComponent *, TooltipComponent);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FTooltipWidgetDisplayData GrabTooltipData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FTooltipWidgetDisplayData AttachTooltipData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FTooltipProximityBadgeVisibilityData TooltipProximityData;

    UPROPERTY(BlueprintAssignable)
    FPushCableSlotTooltip OnPushCableSlotTooltip;

    UPROPERTY(BlueprintAssignable)
    FPopCableSlotTooltip OnPopCableSlotTooltip;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCableTutorialComplete;

protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool CableTutorialIsComplete;

private:
    UPROPERTY()
    TArray<FSlotReference> ReceiverCableSlots;

    UPROPERTY()
    TArray<FSlotReference> ProviderCableSlots;

    UPROPERTY()
    APhysicalItem *receiverItem;

    UPROPERTY()
    APhysicalItem *providerItem;

    UPROPERTY(Export)
    USlotsComponent *ReceiverSlotComponent;

    UPROPERTY(Export)
    USlotsComponent *ProviderSlotComponent;

    UPROPERTY(Export)
    UTooltipComponent *CurrentGrabTooltipComponent;

    UPROPERTY(Export)
    UTooltipComponent *CurrentAttachTooltipComponent;

public:
    UCableTutorialComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopCableTutorial();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupCableTutorial(APhysicalItem *NewReceiverItem, APhysicalItem *NewProviderItem, bool completeIfReceiverAlreadyPowered);

private:
    UFUNCTION()
    void OnReceiverItemSlotted();

    UFUNCTION()
    void OnReceiverItemPickedUp(bool physicalMovementOrNewOwner);

    UFUNCTION()
    void OnReceiverItemPadSpawned();

    UFUNCTION()
    void OnReceiverItemDropped(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

    UFUNCTION()
    void OnProviderItemSlotted();

    UFUNCTION()
    void OnProviderItemPickedUp(bool physicalMovementOrNewOwner);

    UFUNCTION()
    void OnProviderItemPadSpawned();

    UFUNCTION()
    void OnProviderItemDropped(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

protected:
    UFUNCTION()
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection *cable);
};
