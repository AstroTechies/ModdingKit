#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "TradeOutput.h"
#include "ItemTradeValueTable.generated.h"

class UItemType;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UItemTradeValueTable : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TMap<TSubclassOf<UItemType>, FTradeOutput> ItemTradeValueTable;

    UItemTradeValueTable();
};
