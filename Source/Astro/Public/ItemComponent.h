#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnItemTypeChangedDelegate.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "ItemComponent.generated.h"

class AActor;
class UAstroSaveCustomArchiveProxy;
class UItemComponent;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UItemComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float StartingAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Discrete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float Capacity;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnRecipeAmountChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDrained;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal PostDrained;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFilled;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnNoLongerEmpty;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnNoLongerFull;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeChanged OnLiteralItemTypeChangedAuthority;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeChanged OnStoredSubItemTypeChangedAuthority;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> storedSubItemType;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRepAmount, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
public:
    UItemComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRepAmount(int32 previousAmount);
    
    UFUNCTION(BlueprintCallable)
    void OnRep();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmptyContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveItem(TSubclassOf<UItemType> Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetStoredSubItemTypeClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetStoredSubItemTypeCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRecipeAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetLiteralItemTypeClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetLiteralItemTypeCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetInstanceCount(int32 maxNumInstances) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetFunctionalItemTypeClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetFunctionalItemTypeCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFullness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemComponent* GetActorItemComponent(AActor* Actor);
    
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
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AcceptsChangeInAmountForItemType(TSubclassOf<UItemType> itemTypeForChange, bool changeIsPositive) const;
    
};

