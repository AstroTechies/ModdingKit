#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "HangingSlotComponent.generated.h"

class APlayController;
class ASlotConnection;
class URingCameraTargeter;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UHangingSlotComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference HangingSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference ResourceSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HangingSlotDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsReadyActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URingCameraTargeter* RingTargeter;
    
    UHangingSlotComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void PositionConnection(ASlotConnection* Connection, APlayController* Controller, FVector& outNormal, FVector& OutLocation);
    
    UFUNCTION(BlueprintCallable)
    void ConnectAndTargetSlot(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    void ConnectAndTarget(ASlotConnection* Connection);
    
};

