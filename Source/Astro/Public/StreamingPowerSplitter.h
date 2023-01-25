#pragma once
#include "CoreMinimal.h"
#include "EPowerCableConnectionDirection.h"
#include "PhysicalItem.h"
#include "SlotReference.h"
#include "StreamingPowerSplitterReplicationData.h"
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
    UFUNCTION(BlueprintCallable)
    void OnRep_SplitterData();
    
    UFUNCTION(BlueprintCallable)
    void HandleCableConnectionMade(FSlotReference SlotRef, ASlotConnection* Connection);
    
    UFUNCTION(BlueprintCallable)
    void HandleCableConnectionInterrupted(UActorStreamingPowerCableComponent* powerCable, bool bInterrupted);
    
    UFUNCTION(BlueprintCallable)
    void HandleCableConnectionBroken(FSlotReference SlotRef, ASlotConnection* Connection);
    
    UFUNCTION(BlueprintCallable)
    EPowerCableConnectionDirection GetDirectionOfCableForSlot(const FSlotReference& ConnectedSlot);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ChangePowerSplitRatios(const TArray<float>& SplitRatios);
    
};

