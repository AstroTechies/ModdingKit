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

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API URailComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUpdateRailCart OnUpdateCart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRailItem> RailItems;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference NotifySlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASlotConnection* OwnerConnection;
    
public:
    URailComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool SendItem(APhysicalItem* Item, AActor* Source);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastSendRail(bool Immediate);
    
};

