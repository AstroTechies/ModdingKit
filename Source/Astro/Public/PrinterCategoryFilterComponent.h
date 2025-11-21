#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnPrintFilterReplicationDataChangedDelegate.h"
#include "PrintFilterReplicatedState.h"
#include "Templates/SubclassOf.h"
#include "PrinterCategoryFilterComponent.generated.h"

class APhysicalItem;
class UItemCatalog;
class UItemCatalogCategoryDefinition;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPrinterCategoryFilterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> BaseItemTypeT1Categories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> BaseItemTypeT2Categories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> BaseItemTypeT3Categories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ReplicationData, meta=(AllowPrivateAccess=true))
    FPrintFilterReplicatedState PrintFilterReplicatedState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPrintFilterReplicationDataChanged OnReplicationDataChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<bool> PrinterTypePresenceStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemCatalog* ItemCatalog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemCatalogCategoryDefinition* AllCatalogItemsCategory;
    
    UPrinterCategoryFilterComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetPrinterIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentSelectionIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void RemoveT3FilteredBaseItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveT2FilteredBaseItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveT1FilteredBaseItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSlottedT3Printer(APhysicalItem* printer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSlottedT2Printer(APhysicalItem* printer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSlottedT1Printer(APhysicalItem* printer);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ReplicationData();
    
    UFUNCTION(BlueprintCallable)
    void OnCreativeModeCatalogUnlockedChanged();
    
    UFUNCTION(BlueprintCallable)
    void KnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentSelectionIndex();
    
    UFUNCTION(BlueprintCallable)
    TArray<TSubclassOf<UItemType>> GetCategoryItemListForBastItemType(TSubclassOf<UItemType> BaseItemType);
    
    UFUNCTION(BlueprintCallable)
    void AddT3FilteredBaseItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void AddT2FilteredBaseItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void AddT1FilteredBaseItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void AddSlottedT3Printer(APhysicalItem* printer);
    
    UFUNCTION(BlueprintCallable)
    void AddSlottedT2Printer(APhysicalItem* printer);
    
    UFUNCTION(BlueprintCallable)
    void AddSlottedT1Printer(APhysicalItem* printer);
    
};

