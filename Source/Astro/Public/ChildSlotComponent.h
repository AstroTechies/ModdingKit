#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CustomChildActorComponent.h"
#include "ESlottableItemsFiltrationListBehavior.h"
#include "EAuxSlotType.h"
#include "ESlotConfiguration.h"
#include "ESlotConnectorType.h"
#include "SlotReference.h"
#include "ChildSlotComponent.generated.h"

class UItemList;
class UItemType;
class AItemSlot;
class APhysicalItem;
class UItemListWeighted;
class UPhysicalItemSpawnList;
class URewardSelectionTemplate;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UChildSlotComponent : public UCustomChildActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AItemSlot> ChildSlotClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemList> SlottableItemsFiltrationList;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ESlottableItemsFiltrationListBehavior SlottableItemsFiltrationListBehavior;

    UPROPERTY(EditAnywhere)
    uint8 SlotVisible : 1;

    UPROPERTY(EditAnywhere)
    uint8 Unclickable : 1;

    UPROPERTY(EditAnywhere)
    uint8 Breakable : 1;

    UPROPERTY(EditAnywhere)
    uint8 ConnectionPullAllowed : 1;

    UPROPERTY(EditAnywhere)
    uint8 HideConnectorOnPull : 1;

    UPROPERTY(EditAnywhere)
    uint8 GeneratesNoCollision : 1;

    UPROPERTY(EditAnywhere)
    uint8 AllowBodySlotAttach : 1;

    UPROPERTY(EditAnywhere)
    uint8 WeldItems : 1;

    UPROPERTY(EditAnywhere)
    uint8 bSpawnStartingPhysicalItemPackaged : 1;

    UPROPERTY(EditAnywhere)
    EAuxSlotType AuxSlotType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ESlotConnectorType ConnectorType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ESlotConfiguration Configuration;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> StartingItemType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<APhysicalItem> StartingPhysicalItemType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemListWeighted> StartingItemList;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UPhysicalItemSpawnList> StartingActorList;

    UPROPERTY(EditAnywhere)
    TSubclassOf<URewardSelectionTemplate> StartingRewardSelection;

    UChildSlotComponent();
    UFUNCTION(BlueprintCallable)
    void SetChildSlotClass(TSubclassOf<AItemSlot> InClass);

    UFUNCTION(BlueprintPure)
    FSlotReference MakeReference();
};
