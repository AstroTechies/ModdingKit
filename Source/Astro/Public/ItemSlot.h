#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "ESlotType.h"
#include "UObject/NoExportTypes.h"
#include "ItemSlot.generated.h"

class USlotBehavior;
class AItemSlot;
class UClickableComponent;
class USubslot;
class ASlotConnection;
class APhysicalItem;
class UChildSlotComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AItemSlot : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ESlotType SlotType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AItemSlot> BaseClassType;

    UPROPERTY(EditAnywhere)
    TArray<TSubclassOf<USlotBehavior>> Behaviors;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    USubslot *Subslot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<ASlotConnection> ConnectionClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector ConnectionAnchorOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool SingleConnection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ItemBlocksConnection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ConnectionBlocksItem;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ConnectionTense;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool PowerIncomingOnly;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool StreamingPowerConnectionsMergePowerNodes;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool CanAcceptUnslottableItems;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool IsTrailerHitch;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 SlotTier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 SlotTierCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool CanHoldItem;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UClickableComponent *ClickableComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool CanAcceptItems;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString HoverSoundEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString AttachSoundEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString DetachSoundEvent;

    AItemSlot();
    UFUNCTION(BlueprintImplementableEvent)
    void OnItemSet(APhysicalItem *LastItem, APhysicalItem *NewItem);

    UFUNCTION(BlueprintImplementableEvent)
    void OnItemReleased(APhysicalItem *LastItem);

    UFUNCTION(BlueprintNativeEvent)
    void OnConnectionDestroyed(UChildSlotComponent *Other, bool IsSource);

    UFUNCTION(BlueprintNativeEvent)
    void OnConnectionBuilt(ASlotConnection *Connection, bool IsSource);

    UFUNCTION(BlueprintImplementableEvent)
    void OnBuildingConnection(ASlotConnection *Connection);

    UFUNCTION(BlueprintNativeEvent)
    bool AcceptsItem(APhysicalItem *Item);
};
