#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TradeShipDockComponent.h"
#include "TradeShipDockComponent_Whitelist.generated.h"

class UItemType;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent_Whitelist : public UTradeShipDockComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UItemType>> ItemTypeWhitelist;

public:
    UTradeShipDockComponent_Whitelist();
};
