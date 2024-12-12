#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AuxSlotItemTooltipComponent.generated.h"

class AAstroPlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAuxSlotItemTooltipComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TooltipTimeoutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideInputActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputActionNameOverride;
    
    UAuxSlotItemTooltipComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void TooltipTimeout();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable, WithValidation)
    void MulticastOnOwnerItemAuxUsed(AAstroPlayerController* controllingPlayer);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
    UFUNCTION(BlueprintCallable)
    void HandleReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
};

