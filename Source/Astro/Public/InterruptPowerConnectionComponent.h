#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "EnableSignalDelegate.h"
#include "InterruptPowerConnectionComponent.generated.h"

class ASlotConnection;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UInterruptPowerConnectionComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnConnectionInterruped;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> PowerSlots;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_ConnectionInterrupted, meta = (AllowPrivateAccess = true))
    uint8 bConnectionInterrupted : 1;

    UInterruptPowerConnectionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ToggleInterrupt(bool bInterrupt);

private:
    UFUNCTION()
    void OnRep_ConnectionInterrupted();

    UFUNCTION()
    void OnConnectionPostComplete(FSlotReference Slot, ASlotConnection *Connection);
};
