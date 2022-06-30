#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TradeShipDockComponent.h"
#include "TradeShipDockComponent_ItemType.generated.h"

class UItemType;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent_ItemType : public UTradeShipDockComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly, ReplicatedUsing = OnRep_ItemType)
    TSubclassOf<UItemType> ItemType;

public:
    UTradeShipDockComponent_ItemType();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_ItemType();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetItemType(TSubclassOf<UItemType> NewItemType);
};
