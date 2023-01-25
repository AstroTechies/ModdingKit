#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnableSignalDelegate.h"
#include "SlotReference.h"
#include "InterruptPowerConnectionComponent.generated.h"

class ASlotConnection;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UInterruptPowerConnectionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnConnectionInterruped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> PowerSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ConnectionInterrupted, meta=(AllowPrivateAccess=true))
    uint8 bConnectionInterrupted: 1;
    
    UInterruptPowerConnectionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ToggleInterrupt(bool bInterrupt);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_ConnectionInterrupted();
    
    UFUNCTION(BlueprintCallable)
    void OnConnectionPostComplete(FSlotReference Slot, ASlotConnection* Connection);
    
};

