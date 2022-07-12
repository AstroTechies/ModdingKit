#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "CurrentlySelectedItemChangedDelegate.h"
#include "CheatPlinthBase.generated.h"

class UItemType;
class UItemList;

UCLASS(Abstract, Blueprintable)
class ASTRO_API ACheatPlinthBase : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemList* SpawnableItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SelectionIndex, meta=(AllowPrivateAccess=true))
    int32 SelectionIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> CurrentlySelectedItemType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurrentlySelectedItemChanged OnCurrentlySelectedItemChanged;
    
public:
    ACheatPlinthBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_SelectionIndex();
    
    UFUNCTION(BlueprintCallable)
    void IncrementSelectionIndex();
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetCurrentlySelectedItemType();
    
    UFUNCTION(BlueprintCallable)
    void DecrementSelectionIndex();
    
};

