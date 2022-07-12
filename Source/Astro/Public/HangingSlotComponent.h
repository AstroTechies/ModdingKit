#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "SlotReference.h"
#include "HangingSlotComponent.generated.h"

class URingCameraTargeter;
class ASlotConnection;
class APlayController;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    URingCameraTargeter* RingTargeter;
    
    UHangingSlotComponent();
    UFUNCTION(BlueprintCallable)
    void PositionConnection(ASlotConnection* Connection, APlayController* Controller, FVector& outNormal, FVector& OutLocation);
    
    UFUNCTION(BlueprintCallable)
    void ConnectAndTargetSlot(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    void ConnectAndTarget(ASlotConnection* Connection);
    
};

