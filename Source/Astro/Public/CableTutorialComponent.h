#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ECableTutorialStep.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "TooltipWidgetDisplayData.h"
#include "CableTutorialComponent.generated.h"

class APhysicalItem;
class ASlotConnection;
class UPrimitiveComponent;
class USlotsComponent;
class UTooltipComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCableTutorialComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPushCableSlotTooltip, UTooltipComponent*, TooltipComponent, ECableTutorialStep, InteractionStep);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPopCableSlotTooltip, UTooltipComponent*, TooltipComponent);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData GrabTooltipData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData AttachTooltipData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipProximityBadgeVisibilityData TooltipProximityData;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPushCableSlotTooltip OnPushCableSlotTooltip;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPopCableSlotTooltip OnPopCableSlotTooltip;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCableTutorialComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CableTutorialIsComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ReceiverCableSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ProviderCableSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* receiverItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* providerItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USlotsComponent* ReceiverSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USlotsComponent* ProviderSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CurrentGrabTooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CurrentAttachTooltipComponent;
    
public:
    UCableTutorialComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopCableTutorial();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupCableTutorial(APhysicalItem* NewReceiverItem, APhysicalItem* NewProviderItem, bool completeIfReceiverAlreadyPowered);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnReceiverItemSlotted();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiverItemPickedUp(bool physicalMovementOrNewOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnReceiverItemPadSpawned();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiverItemDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void OnProviderItemSlotted();
    
    UFUNCTION(BlueprintCallable)
    void OnProviderItemPickedUp(bool physicalMovementOrNewOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnProviderItemPadSpawned();
    
    UFUNCTION(BlueprintCallable)
    void OnProviderItemDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable);
    
};

