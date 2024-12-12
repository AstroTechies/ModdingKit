#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickUpOnSpawnComponent.generated.h"

class APlayController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPickUpOnSpawnComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPickUpOnSpawnComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerOnHandledLocalPickUp();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable, WithValidation)
    void MulticastSetOwningPlayer(APlayController* Player);
    
    UFUNCTION(BlueprintCallable)
    void HandleOwnerChanged();
    
};

