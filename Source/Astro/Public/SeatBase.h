#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "SeatReplicationData.h"
#include "SeatBase.generated.h"

class AVehicleBase;
class UActorAttachmentsComponent;

UCLASS(Abstract, Blueprintable)
class ASeatBase : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FSeatReplicationData SeatReplicationData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorAttachmentsComponent* ActorAttachmentsComponent;
    
public:
    ASeatBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void HandleSeatReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void HandleSeatPlacedInSlot();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AVehicleBase* GetVehicleSlottedTo() const;
    
};

