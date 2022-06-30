#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "SeatReplicationData.h"
#include "SeatBase.generated.h"

class AVehicleBase;
class UActorAttachmentsComponent;

UCLASS(Blueprintable, Abstract)
class ASeatBase : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Replicated)
    FSeatReplicationData SeatReplicationData;

private:
    UPROPERTY(Export)
    UActorAttachmentsComponent *ActorAttachmentsComponent;

public:
    ASeatBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void HandleSeatReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandleSeatPlacedInSlot();

public:
    UFUNCTION(BlueprintPure)
    AVehicleBase *GetVehicleSlottedTo() const;
};
