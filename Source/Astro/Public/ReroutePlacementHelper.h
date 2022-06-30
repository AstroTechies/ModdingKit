#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ReroutePlacementHelper.generated.h"

class UActuatorComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AReroutePlacementHelper : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(Export, Transient)
    UActuatorComponent *ActuatorComponent;

    AReroutePlacementHelper();
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerTryDeleteNode();

    UFUNCTION()
    void OnUsePressed();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastStateChange(bool pickedUp);
};
