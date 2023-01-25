#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TradeShipDockComponent.h"
#include "TradeShipDockComponent_ItemType.generated.h"

class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent_ItemType : public UTradeShipDockComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ItemType, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
public:
    UTradeShipDockComponent_ItemType();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ItemType();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetItemType(TSubclassOf<UItemType> NewItemType);
    
};

