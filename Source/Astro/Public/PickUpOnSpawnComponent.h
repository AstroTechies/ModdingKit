#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "PickUpOnSpawnComponent.generated.h"

class APlayController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPickUpOnSpawnComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPickUpOnSpawnComponent();
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerOnHandledLocalPickUp();
    
    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void MulticastSetOwningPlayer(APlayController* Player);
    
    UFUNCTION()
    void HandleOwnerChanged();
    
};

