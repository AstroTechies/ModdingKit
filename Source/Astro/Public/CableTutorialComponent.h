#pragma once
#include "CoreMinimal.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ECableTutorialStep.h"
#include "TooltipWidgetDisplayData.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "SlotReference.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "CableTutorialComponent.generated.h"

class UTooltipComponent;
class APhysicalItem;
class USlotsComponent;
class UPrimitiveComponent;
class ASlotConnection;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USlotsComponent* ReceiverSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USlotsComponent* ProviderSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CurrentGrabTooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CurrentAttachTooltipComponent;
    
public:
    UCableTutorialComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopCableTutorial();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupCableTutorial(APhysicalItem* NewReceiverItem, APhysicalItem* NewProviderItem, bool completeIfReceiverAlreadyPowered);
    
private:
    UFUNCTION()
    void OnReceiverItemSlotted();
    
    UFUNCTION()
    void OnReceiverItemPickedUp(bool physicalMovementOrNewOwner);
    
    UFUNCTION()
    void OnReceiverItemPadSpawned();
    
    UFUNCTION()
    void OnReceiverItemDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION()
    void OnProviderItemSlotted();
    
    UFUNCTION()
    void OnProviderItemPickedUp(bool physicalMovementOrNewOwner);
    
    UFUNCTION()
    void OnProviderItemPadSpawned();
    
    UFUNCTION()
    void OnProviderItemDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
protected:
    UFUNCTION()
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION()
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION()
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable);
    
};

