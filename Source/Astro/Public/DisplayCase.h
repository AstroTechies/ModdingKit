#pragma once
#include "CoreMinimal.h"
#include "CollectionData.h"
#include "ECollectionReward.h"
#include "ELRDType.h"
#include "PhysicalItem.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "DisplayCase.generated.h"

class ADisplayCaseShelf;
class UDisplayCaseDataAsset;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API ADisplayCase : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCollectionComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCollectionIncomplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSlottedItemsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDisplayDataChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDisplayCaseDataAsset* DisplayCaseDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CurrentDisplayData, meta=(AllowPrivateAccess=true))
    FCollectionData CurrentDisplayData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_UniqueSlottedItems, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UniqueSlottedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_UniqueSlottedItems, meta=(AllowPrivateAccess=true))
    TArray<ELRDType> UniqueSlottedLRDTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ManagedSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxNumOfShelves;
    
public:
    ADisplayCase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void OnRep_UniqueSlottedItems() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentDisplayData() const;
    
    UFUNCTION(BlueprintCallable)
    void OnItemSetInShelf(APhysicalItem* inItem, ADisplayCaseShelf* inShelf);
    
    UFUNCTION(BlueprintCallable)
    void OnItemReleasedFromShelf(APhysicalItem* inItem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ELRDType> GetUniqueSlottedLRDTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSubclassOf<UItemType>> GetUniqueSlottedItems() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECollectionReward GetCurrentCollectionReward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FCollectionData GetCollectionData() const;
    
private:
    UFUNCTION(BlueprintCallable)
    bool CheckIfMuseumIsOnCurrentPlanet();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityTrySetBuffRewardInactive();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityToggleBuffRewardActive();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityRemoveShelf(APhysicalItem* inPhysicalItem);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityAddShelf(APhysicalItem* inPhysicalItem);
    
};

