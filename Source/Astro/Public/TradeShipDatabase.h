#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "TradeShipDatabase.generated.h"

class AActor;

UCLASS(Blueprintable)
class UTradeShipDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, TSoftClassPtr<AActor>> TradeShips;
    
    UTradeShipDatabase();
};

