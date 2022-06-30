#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TradeShipDatabase.generated.h"

class AActor;

UCLASS(Blueprintable, Blueprintable)
class UTradeShipDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TMap<FString, TSoftClassPtr<AActor>> TradeShips;

    UTradeShipDatabase();
};
