#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnUpdateRailCartDelegate.h"
#include "RailItem.h"
#include "SlotReference.h"
#include "RailComponent.generated.h"

class AActor;
class APhysicalItem;
class ASlotConnection;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API URailComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnUpdateRailCart OnUpdateCart;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MoveSpeed;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FRailItem> RailItems;

private:
    UPROPERTY(Transient)
    FSlotReference NotifySlot;

    UPROPERTY()
    ASlotConnection *OwnerConnection;

public:
    URailComponent();
    UFUNCTION(BlueprintCallable)
    bool SendItem(APhysicalItem *Item, AActor *Source);

private:
    UFUNCTION(NetMulticast, Unreliable)
    void MulticastSendRail(bool Immediate);
};
