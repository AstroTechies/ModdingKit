#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "HangingSlotComponent.generated.h"

class URingCameraTargeter;
class ASlotConnection;
class APlayController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UHangingSlotComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    FSlotReference HangingSlot;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference ResourceSlot;

    UPROPERTY(EditAnywhere)
    float HangingSlotDistance;

    UPROPERTY(EditAnywhere)
    bool IsReadyActor;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    URingCameraTargeter *RingTargeter;

    UHangingSlotComponent();
    UFUNCTION(BlueprintCallable)
    void PositionConnection(ASlotConnection *Connection, APlayController *Controller, FVector &outNormal, FVector &OutLocation);

    UFUNCTION(BlueprintCallable)
    void ConnectAndTargetSlot(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    void ConnectAndTarget(ASlotConnection *Connection);
};
