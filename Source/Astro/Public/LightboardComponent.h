#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "SlotItemHighlightInterface.h"
#include "LightboardComponent.generated.h"

class APlayController;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API ULightboardComponent : public UActorComponent, public ISlotItemHighlightInterface
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, FName> ActuateSlotMapping;

public:
    ULightboardComponent();

protected:
    UFUNCTION()
    void HandleSlotActuateEvent(FSlotReference pinSlot, APlayController *Instigator);

    // Fix for true pure virtual functions not being implemented
};
