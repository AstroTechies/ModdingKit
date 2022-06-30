#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotReference.h"
#include "ReplicatedPrinterState.generated.h"

class APhysicalItem;
class UItemType;

USTRUCT(BlueprintType)
struct FReplicatedPrinterState {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TSubclassOf<APhysicalItem> CurrentBlueprintItem;
    
    UPROPERTY(SaveGame)
    TSubclassOf<APhysicalItem> CurrentBlueprintItemBeingPrinted;
    
    UPROPERTY()
    TArray<TSubclassOf<UItemType>> NeededItems;
    
    UPROPERTY()
    TArray<int32> AvailableIngredients;
    
    UPROPERTY()
    FSlotReference PrinterOutputSlot;
    
    UPROPERTY()
    float VisualProgress;
    
    UPROPERTY()
    float ModifiedProductionRate;
    
    UPROPERTY()
    int32 IndexAmongUnlockedBlueprints;
    
    UPROPERTY()
    int32 TotalNumUnlockedBlueprints;
    
    UPROPERTY(SaveGame)
    uint8 bCanPrint: 1;
    
    UPROPERTY(SaveGame)
    uint8 bCanUse: 1;
    
    UPROPERTY(SaveGame)
    uint8 bCharging: 1;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bPrinting: 1;
    
    UPROPERTY()
    uint8 bOutputSlotFree: 1;
    
    UPROPERTY()
    uint8 bHideIndicator: 1;
    
    UPROPERTY()
    uint8 bControlPanelEngaged: 1;
    
    ASTRO_API FReplicatedPrinterState();
};

