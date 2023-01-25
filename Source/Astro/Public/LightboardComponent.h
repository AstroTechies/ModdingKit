#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotItemHighlightInterface.h"
#include "SlotReference.h"
#include "LightboardComponent.generated.h"

class APlayController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API ULightboardComponent : public UActorComponent, public ISlotItemHighlightInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> ActuateSlotMapping;
    
public:
    ULightboardComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void HandleSlotActuateEvent(FSlotReference pinSlot, APlayController* Instigator);
    
    
    // Fix for true pure virtual functions not being implemented
};

