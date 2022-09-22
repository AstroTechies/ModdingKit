#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "AuxSlotItemTooltipComponent.generated.h"

class AAstroPlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAuxSlotItemTooltipComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TooltipTimeoutDuration;
    
    UAuxSlotItemTooltipComponent();
private:
    UFUNCTION()
    void TooltipTimeout();
    
public:
    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void MulticastOnOwnerItemAuxUsed(AAstroPlayerController* controllingPlayer);
    
protected:
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
    UFUNCTION()
    void HandleReleasedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void HandlePlacedInSlot();
    
};

