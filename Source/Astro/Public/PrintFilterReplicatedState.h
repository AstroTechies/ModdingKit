#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PrintFilterReplicatedState.generated.h"

class APhysicalItem;
class UItemType;

USTRUCT(BlueprintType)
struct FPrintFilterReplicatedState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> SlottedT1Printers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> SlottedT2Printers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> SlottedT3Printers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> FilteredT1BaseItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> FilteredT2BaseItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> FilteredT3BaseItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentPrinterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> CurrentSelectionIndexes;
    
    ASTRO_API FPrintFilterReplicatedState();
};

