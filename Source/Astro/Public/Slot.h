#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ESlotType.h"
#include "ESlotPosition.h"
#include "ESlottableItemsFiltrationListBehavior.h"
#include "EAuxSlotType.h"
#include "ESlotConfiguration.h"
#include "ESlotConnectorType.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SubslotIndicatorType.h"
#include "SubSlotLocation.h"
#include "ENumRotations.h"
#include "SlotReference.h"
#include "Slot.generated.h"

class UPhysicalItemSpawnList;
class AItemSlot;
class UItemType;
class USceneComponent;
class APhysicalItem;
class UTooltipComponent;
class UItemListWeighted;
class URewardSelectionTemplate;
class UItemList;
class ASlotConnection;
class USlotBehavior;
class USlotDelegates;
class AResourceInfo;
class UPrimitiveComponent;
class USlotsComponent;
class USlotOrganizationRule;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FSlot {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<AItemSlot> SlotTemplate;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ESlotType SlotType;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ESlotConnectorType ConnectorType;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SlotTier;
    
    UPROPERTY()
    int32 SlotBinaryTreeDepth;
    
    UPROPERTY(EditAnywhere)
    int32 SlotTierCount;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Breakable;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool IsReserved;
    
    UPROPERTY(EditAnywhere)
    ESlotConfiguration Configuration;
    
    UPROPERTY(EditAnywhere)
    ESlotPosition PositionType;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName TargetName;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName SocketName;
    
    UPROPERTY(EditAnywhere)
    FTransform RelativeOffset;
    
    UPROPERTY(EditAnywhere)
    FVector ConnectionAdditionalRelativeOffset;
    
    UPROPERTY(EditAnywhere)
    TArray<FSubSlotLocation> SubslotLocations;
    
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
    
    UPROPERTY(EditAnywhere)
    bool bSpawnStartingPhysicalItemPackaged;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<ASlotConnection> ConnectionClass;
    
    UPROPERTY(EditAnywhere)
    TArray<USlotBehavior*> Behaviors;
    
    UPROPERTY(EditAnywhere)
    ENumRotations NumberOfRotations;
    
    UPROPERTY(EditAnywhere)
    uint8 bIsBodySlot: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bAllowBodySlotAttach: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bGenerateNoCollision: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bCanHoldItem: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bItemBlocksConnection: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bConnectionBlocksItem: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bNoConnectionPull: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bSingleConnection: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bHideConnectorOnPull: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bConnectionTense: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bUnclickable: 1;
    
    UPROPERTY(Transient)
    uint8 bIsManagedByRule: 1;
    
private:
    UPROPERTY(Transient)
    uint8 bHasExternallyManagedConnection: 1;
    
public:
    UPROPERTY(EditAnywhere)
    uint8 bCanAcceptUnslottableItems: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bIsTrailerHitch: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bPowerIncomingOnly: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bStreamingPowerConnectionsMergeNodes: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bWeldItems: 1;
    
    UPROPERTY(EditAnywhere)
    EAuxSlotType AuxSlotType;
    
    UPROPERTY(EditAnywhere)
    float TraceRadius;
    
    UPROPERTY(EditAnywhere)
    float IndicatorScale;
    
    UPROPERTY(EditAnywhere)
    FString HoverSoundEvent;
    
    UPROPERTY(EditAnywhere)
    FString AttachSoundEvent;
    
    UPROPERTY(EditAnywhere)
    FString DetachSoundEvent;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemList> SlottableItemsFiltrationList;
    
    UPROPERTY(EditAnywhere)
    ESlottableItemsFiltrationListBehavior SlottableItemsFiltrationListBehavior;
    
    UPROPERTY(Export, Transient)
    UTooltipComponent* SlotTooltipComponent;
    
    UPROPERTY(Transient)
    TArray<APhysicalItem*> SlottedItems;
    
    UPROPERTY(Transient)
    TArray<FSubslotIndicatorType> SlotIndicatorTypes;
    
    UPROPERTY(Transient)
    AResourceInfo* SlotResourceInfo;
    
    UPROPERTY(Export, Transient)
    UPrimitiveComponent* TracePrimitive;
    
    UPROPERTY(Export, Transient)
    USceneComponent* PositionComponent;
    
    UPROPERTY(Export, Transient)
    USlotsComponent* Owner;
    
    UPROPERTY(Transient)
    USlotOrganizationRule* OwnerRule;
    
    UPROPERTY(Transient)
    FSlotReference CurrentBodySlot;
    
    UPROPERTY(Transient)
    TArray<ASlotConnection*> ExternalConnections;
    
    UPROPERTY(Transient)
    TArray<ASlotConnection*> IndicatorConnections;
    
    UPROPERTY(Transient)
    ASlotConnection* BuildingConnection;
    
    UPROPERTY(Export, Transient)
    TArray<UStaticMeshComponent*> LegacyMeshes;
    
    UPROPERTY(Transient)
    TArray<FTransform> LegacyMeshRelativeTransforms;
    
    UPROPERTY(Export, Transient)
    TArray<UStaticMeshComponent*> ConnectorMeshes;
    
private:
    UPROPERTY(Transient)
    USlotDelegates* Delegates;
    
public:
    ASTRO_API FSlot();
};

