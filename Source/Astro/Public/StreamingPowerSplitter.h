#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "SlotReference.h"
#include "StreamingPowerSplitterReplicationData.h"
#include "EPowerCableConnectionDirection.h"
#include "StreamingPowerSplitter.generated.h"

class ASlotConnection;
class UActorStreamingPowerCableComponent;

UCLASS(Blueprintable)
class ASTRO_API AStreamingPowerSplitter : public APhysicalItem {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateSplitterVisualization);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SplitterData, meta=(AllowPrivateAccess=true))
    FStreamingPowerSplitterReplicationData SplitterRepData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CableSlotNames;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateSplitterVisualization OnUpdateSplitterVisualization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> CableSlotRefs;
    
public:
    AStreamingPowerSplitter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void OnRep_SplitterData();
    
    UFUNCTION()
    void HandleCableConnectionMade(FSlotReference SlotRef, ASlotConnection* Connection);
    
    UFUNCTION()
    void HandleCableConnectionInterrupted(UActorStreamingPowerCableComponent* powerCable, bool bInterrupted);
    
    UFUNCTION()
    void HandleCableConnectionBroken(FSlotReference SlotRef, ASlotConnection* Connection);
    
    UFUNCTION()
    EPowerCableConnectionDirection GetDirectionOfCableForSlot(const FSlotReference& ConnectedSlot);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ChangePowerSplitRatios(const TArray<float>& SplitRatios);
    
};

