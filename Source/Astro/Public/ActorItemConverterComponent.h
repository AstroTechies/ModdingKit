#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EOutputEjectionType.h"
#include "OnItemConverterStateChangedDelegate.h"
#include "OnItemConversionCompleteDelegate.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "OnItemConverterActiveConversionsListChangedDelegate.h"
#include "SlotReference.h"
#include "EnableSignalDelegate.h"
#include "ItemConversionRecipeInputStatus.h"
#include "EInputManagementType.h"
#include "ItemConverterReplicationData.h"
#include "ItemConversionInputItemStatus.h"
#include "ActiveItemConversion.h"
#include "Recipe.h"
#include "EItemConverterState.h"
#include "ActorItemConverterComponent.generated.h"

class UOutputOrganizationRule;
class UItemConversionFormula;
class UItemList;
class URecipeOrganizationRule;
class APhysicalItem;
class UItemType;
class AAstroCharacter;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorItemConverterComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnSystemMigrationCheckStarted;

    UPROPERTY(BlueprintAssignable)
    FOnItemConversionComplete OnAuthorityItemConversionCompleted;

    UPROPERTY(BlueprintAssignable)
    FOnItemConverterActiveConversionsListChanged OnActiveConversionsAdded;

    UPROPERTY(BlueprintAssignable)
    FOnItemConverterActiveConversionsListChanged OnActiveConversionsRemoved;

    UPROPERTY(BlueprintAssignable)
    FOnItemConverterStateChanged OnStateChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnWantsToBeActiveChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnShouldLoopProductionChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnViewDataChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnReplicationDataInitialized;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FName> ManagedDummySlotNames;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FName> InputSlotNames;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FName> OutputSlotNames;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemConversionFormula> ConversionFormulaType;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemList> OutputItemTypeList;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MinPowerUnitProductionTime;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MaxPowerUnitProductionTime;

    UPROPERTY(EditDefaultsOnly)
    EOutputEjectionType DefaultOutputEjectionType;

    UPROPERTY(EditDefaultsOnly)
    float OutputItemEjectionForce;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EInputManagementType InputSlotsOrganizationRuleType;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCannotProcessConversionsInParallel : 1;

    UPROPERTY(EditDefaultsOnly, SaveGame)
    uint8 bShouldLoopProduction : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bInputSlotsAreUnclickable : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bOutputSlotIsUnclickable : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bDetonatesVolatileInputItems : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bShowOutputIndicatorsWhenSelectingRecipe : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bForceRecipeSelection : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCanUseActorItemComponentAsInput : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bProduceOutputsToUniqueSlots : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bKeepPartialOutputBetweenSaves : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bRefundInputResourcesOnCancel : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bIgnoresPower : 1;

protected:
    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnReplicationDataChanged, meta = (AllowPrivateAccess = true))
    FItemConverterReplicationData ReplicationData;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FItemConverterReplicationData PrevReplicationData;

    UPROPERTY()
    TArray<FSlotReference> InputSlotRefs;

    UPROPERTY()
    TArray<FSlotReference> OutputSlotRefs;

    UPROPERTY()
    TWeakObjectPtr<URecipeOrganizationRule> RecipeOrganizationRule;

    UPROPERTY()
    TWeakObjectPtr<UOutputOrganizationRule> OutputOrganizationRule;

public:
    UActorItemConverterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnReplicationDataChanged();

    UFUNCTION()
    void OnAuthorityRemovedActiveItemConversion(const FActiveItemConversion &activeConversion);

    UFUNCTION()
    void OnAuthorityAddedActiveItemConversion(const FActiveItemConversion &activeConversion);

    UFUNCTION(BlueprintPure)
    static bool IsItemConversionRecipeInputStatusValid(const FItemConversionRecipeInputStatus &ItemConversionRecipeInputStatus);

    UFUNCTION(BlueprintPure)
    static bool IsItemConversionInputItemStatusValid(const FItemConversionInputItemStatus &ItemConversionIngredientStatus);

protected:
    UFUNCTION()
    void HandleItemChangedInResourceSlot(APhysicalItem *changedItem);

public:
    UFUNCTION(BlueprintPure)
    bool GetShouldLoopProduction();

    UFUNCTION(BlueprintPure)
    FRecipe GetSelectedOutputRecipe() const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetSelectedOutputItemType() const;

    UFUNCTION(BlueprintPure)
    FItemConversionRecipeInputStatus GetConversionRecipeInputStatus(const FRecipe &Recipe) const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetShouldLoopProduction(bool ShouldLoopProduction);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetSelectedOutputItemTypeIndex(int32 newIndex);

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOutputEjectionType(EOutputEjectionType ActiveOutputEjectionType);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetExternalResourceProviderSlotsForPlayer(AAstroCharacter *controllingPlayer);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetConverterWantsToBeActive(bool Active);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityIncrementSelectedOutputItemTypeIndex(bool AllowIndexWrapping);

protected:
    UFUNCTION()
    void AuthorityHandleItemComponentChanged();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    EItemConverterState AuthorityGetItemConverterState() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityDecrementSelectedOutputItemTypeIndex(bool AllowIndexWrapping);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCancelActiveConversions();
};
