#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "PhysicalItem.h"
#include "StreamingPowerSplitterReplicationData.h"
#include "EPowerCableConnectionDirection.h"
#include "StreamingPowerSplitter.generated.h"

class UActorStreamingPowerCableComponent;
class ASlotConnection;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AStreamingPowerSplitter : public APhysicalItem
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateSplitterVisualization);

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_SplitterData, meta = (AllowPrivateAccess = true))
    FStreamingPowerSplitterReplicationData SplitterRepData;

private:
    UPROPERTY(EditDefaultsOnly)
    TArray<FName> CableSlotNames;

    UPROPERTY(BlueprintAssignable)
    FUpdateSplitterVisualization OnUpdateSplitterVisualization;

    UPROPERTY(Transient)
    TArray<FSlotReference> CableSlotRefs;

public:
    AStreamingPowerSplitter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnRep_SplitterData();

    UFUNCTION()
    void HandleCableConnectionMade(FSlotReference SlotRef, ASlotConnection *Connection);

    UFUNCTION()
    void HandleCableConnectionInterrupted(UActorStreamingPowerCableComponent *powerCable, bool bInterrupted);

    UFUNCTION()
    void HandleCableConnectionBroken(FSlotReference SlotRef, ASlotConnection *Connection);

    UFUNCTION()
    EPowerCableConnectionDirection GetDirectionOfCableForSlot(const FSlotReference &ConnectedSlot);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ChangePowerSplitRatios(const TArray<float> &SplitRatios);
};
