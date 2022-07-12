#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TradeShipDockComponent.h"
#include "TradeShipDockComponent_Whitelist.generated.h"

class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent_Whitelist : public UTradeShipDockComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> ItemTypeWhitelist;
    
public:
    UTradeShipDockComponent_Whitelist();
};

