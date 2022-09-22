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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActorAttachmentsComponent* ActorAttachmentsComponent;
    
public:
    ASeatBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void HandleSeatReleasedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void HandleSeatPlacedInSlot();
    
public:
    UFUNCTION(BlueprintPure)
    AVehicleBase* GetVehicleSlottedTo() const;
    
};

