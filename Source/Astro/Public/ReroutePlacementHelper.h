#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ReroutePlacementHelper.generated.h"

class UActuatorComponent;

UCLASS(Blueprintable)
class ASTRO_API AReroutePlacementHelper : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActuatorComponent* ActuatorComponent;
    
    AReroutePlacementHelper(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTryDeleteNode();
    
    UFUNCTION(BlueprintCallable)
    void OnUsePressed();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStateChange(bool pickedUp);
    
};

