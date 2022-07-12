#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ReroutePlacementHelper.generated.h"

class UActuatorComponent;

UCLASS(Blueprintable)
class ASTRO_API AReroutePlacementHelper : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UActuatorComponent* ActuatorComponent;
    
    AReroutePlacementHelper();
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerTryDeleteNode();
    
    UFUNCTION()
    void OnUsePressed();
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastStateChange(bool pickedUp);
    
};

