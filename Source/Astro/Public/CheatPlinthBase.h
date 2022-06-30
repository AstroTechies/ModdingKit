#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "CurrentlySelectedItemChangedDelegate.h"
#include "CheatPlinthBase.generated.h"

class UItemList;
class UItemType;

UCLASS(Blueprintable, Abstract)
class ASTRO_API ACheatPlinthBase : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    UItemList *SpawnableItems;

    UPROPERTY(ReplicatedUsing = OnRep_SelectionIndex)
    int32 SelectionIndex;

    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> CurrentlySelectedItemType;

    UPROPERTY(BlueprintAssignable)
    FCurrentlySelectedItemChanged OnCurrentlySelectedItemChanged;

public:
    ACheatPlinthBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

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
