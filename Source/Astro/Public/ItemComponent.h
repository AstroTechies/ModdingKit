#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "OnItemTypeChangedDelegate.h"
#include "ItemComponent.generated.h"

class AActor;
class UItemType;
class UAstroSaveCustomArchiveProxy;
class UItemComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UItemComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float StartingAmount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    bool Discrete;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float Capacity;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnChanged;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnRecipeAmountChanged;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnDrained;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal PostDrained;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnFilled;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnNoLongerEmpty;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnNoLongerFull;

    UPROPERTY(BlueprintAssignable)
    FOnItemTypeChanged OnLiteralItemTypeChangedAuthority;

    UPROPERTY(BlueprintAssignable)
    FOnItemTypeChanged OnStoredSubItemTypeChangedAuthority;

protected:
    UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite, meta = (AllowPrivateAccess = true), ReplicatedUsing = OnRep)
    TSubclassOf<UItemType> ItemType;

    UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite, meta = (AllowPrivateAccess = true), ReplicatedUsing = OnRep)
    TSubclassOf<UItemType> storedSubItemType;

private:
    UPROPERTY(SaveGame, VisibleInstanceOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true), ReplicatedUsing = OnRepAmount)
    int32 Amount;

public:
    UItemComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    int32 TakeItemRateDelta(float Rate, float DeltaTime);

    UFUNCTION(BlueprintCallable)
    int32 TakeItemRate(float Rate);

    UFUNCTION(BlueprintCallable)
    int32 TakeItem(int32 TakeAmount);

    UFUNCTION(BlueprintCallable)
    void SetItemUsingFullness(TSubclassOf<UItemType> NewItemType, float Fullness, bool suppressItemDrainedFillChangeEventBroadcast);

    UFUNCTION(BlueprintCallable)
    void SetItem(TSubclassOf<UItemType> NewItemType, int32 NewAmount, bool suppressItemDrainedFillChangeEventBroadcast);

    UFUNCTION(BlueprintCallable)
    float SetAmountUsingFullness(float newFullness, bool suppressItemDrainedFillChangeEventBroadcast);

    UFUNCTION(BlueprintCallable)
    int32 SetAmount(int32 NewAmount, bool suppressItemDrainedFillChangeEventBroadcast);

protected:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

private:
    UFUNCTION()
    void OnRepAmount(int32 previousAmount);

    UFUNCTION()
    void OnRep();

public:
    UFUNCTION(BlueprintPure)
    bool IsFull() const;

    UFUNCTION(BlueprintPure)
    bool IsEmptyContainer() const;

    UFUNCTION(BlueprintPure)
    bool IsEmpty() const;

    UFUNCTION(BlueprintPure)
    bool IsContainer() const;

    UFUNCTION(BlueprintPure)
    bool HaveItem(TSubclassOf<UItemType> Type) const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetStoredSubItemTypeClass() const;

    UFUNCTION(BlueprintPure)
    UItemType *GetStoredSubItemTypeCDO() const;

    UFUNCTION(BlueprintPure)
    float GetRecipeAmount() const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetLiteralItemTypeClass() const;

    UFUNCTION(BlueprintPure)
    UItemType *GetLiteralItemTypeCDO() const;

    UFUNCTION(BlueprintPure)
    int32 GetInstanceCount(int32 maxNumInstances) const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetFunctionalItemTypeClass() const;

    UFUNCTION(BlueprintPure)
    UItemType *GetFunctionalItemTypeCDO() const;

    UFUNCTION(BlueprintPure)
    float GetFullness() const;

    UFUNCTION(BlueprintPure)
    int32 GetAmount() const;

    UFUNCTION(BlueprintPure)
    static UItemComponent *GetActorItemComponent(AActor *Actor);

    UFUNCTION(BlueprintCallable)
    void ForceChangePrimaryItemTypeAndStoredSubItemTypeWithAmount(TSubclassOf<UItemType> primaryItemType, TSubclassOf<UItemType> NewStoredSubItemType, int32 NewAmount, bool suppressItemDrainedFillChangeEventBroadcast);

    UFUNCTION(BlueprintCallable)
    void ClearContainer();

    UFUNCTION(BlueprintCallable)
    int32 AddItemRateDelta(TSubclassOf<UItemType> Type, float Rate, float DeltaTime);

    UFUNCTION(BlueprintCallable)
    int32 AddItemRate(TSubclassOf<UItemType> Type, float Rate);

    UFUNCTION(BlueprintCallable)
    int32 AddItem(TSubclassOf<UItemType> Type, int32 AddAmount, bool Actual);

    UFUNCTION(BlueprintPure)
    bool AcceptsChangeInAmountForItemType(TSubclassOf<UItemType> itemTypeForChange, bool changeIsPositive) const;
};
