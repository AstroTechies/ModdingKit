#pragma once
#include "CoreMinimal.h"
#include "CurrentlySelectedItemChangedDelegate.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "CheatPlinthBase.generated.h"

class UItemList;
class UItemType;

UCLASS(Abstract, Blueprintable)
class ASTRO_API ACheatPlinthBase : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemList* SpawnableItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemList* SpawnableItems_GW;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SelectionIndex, meta=(AllowPrivateAccess=true))
    int32 SelectionIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> CurrentlySelectedItemType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurrentlySelectedItemChanged OnCurrentlySelectedItemChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemList* ActiveSpawnableItems;
    
public:
    ACheatPlinthBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_SelectionIndex();
    
    UFUNCTION(BlueprintCallable)
    void IncrementSelectionIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetCurrentlySelectedItemType();
    
    UFUNCTION(BlueprintCallable)
    void DecrementSelectionIndex();
    
};

