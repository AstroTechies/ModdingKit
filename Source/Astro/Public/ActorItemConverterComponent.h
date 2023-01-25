#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActiveItemConversion.h"
#include "EInputManagementType.h"
#include "EItemConverterState.h"
#include "EOutputEjectionType.h"
#include "EnableSignalDelegate.h"
#include "ItemConversionInputItemStatus.h"
#include "ItemConversionRecipeInputStatus.h"
#include "ItemConverterReplicationData.h"
#include "OnItemConversionCompleteDelegate.h"
#include "OnItemConverterActiveConversionsListChangedDelegate.h"
#include "OnItemConverterStateChangedDelegate.h"
#include "Recipe.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "ActorItemConverterComponent.generated.h"

class AAstroCharacter;
class APhysicalItem;
class UItemConversionFormula;
class UItemList;
class UItemType;
class UOutputOrganizationRule;
class URecipeOrganizationRule;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorItemConverterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSystemMigrationCheckStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemConversionComplete OnAuthorityItemConversionCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemConverterActiveConversionsListChanged OnActiveConversionsAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemConverterActiveConversionsListChanged OnActiveConversionsRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemConverterStateChanged OnStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnWantsToBeActiveChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnShouldLoopProductionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnViewDataChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnReplicationDataInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ManagedDummySlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> InputSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> OutputSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemConversionFormula> ConversionFormulaType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> OutputItemTypeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPowerUnitProductionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPowerUnitProductionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOutputEjectionType DefaultOutputEjectionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutputItemEjectionForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputManagementType InputSlotsOrganizationRuleType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCannotProcessConversionsInParallel: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bShouldLoopProduction: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bInputSlotsAreUnclickable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOutputSlotIsUnclickable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDetonatesVolatileInputItems: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShowOutputIndicatorsWhenSelectingRecipe: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bForceRecipeSelection: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCanUseActorItemComponentAsInput: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bProduceOutputsToUniqueSlots: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bKeepPartialOutputBetweenSaves: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRefundInputResourcesOnCancel: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIgnoresPower: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPushUnwantedInputItems: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicationDataChanged, meta=(AllowPrivateAccess=true))
    FItemConverterReplicationData ReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemConverterReplicationData PrevReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlotRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> OutputSlotRefs;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<URecipeOrganizationRule> RecipeOrganizationRule;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UOutputOrganizationRule> OutputOrganizationRule;
    
public:
    UActorItemConverterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void OnReplicationDataChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityRemovedActiveItemConversion(const FActiveItemConversion& activeConversion);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityAddedActiveItemConversion(const FActiveItemConversion& activeConversion);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemConversionRecipeInputStatusValid(const FItemConversionRecipeInputStatus& ItemConversionRecipeInputStatus);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemConversionInputItemStatusValid(const FItemConversionInputItemStatus& ItemConversionIngredientStatus);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleItemChangedInResourceSlot(APhysicalItem* changedItem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShouldLoopProduction();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRecipe GetSelectedOutputRecipe() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetSelectedOutputItemType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemConversionRecipeInputStatus GetConversionRecipeInputStatus(const FRecipe& Recipe) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetShouldLoopProduction(bool ShouldLoopProduction);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetSelectedOutputItemTypeIndex(int32 newIndex);
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOutputEjectionType(EOutputEjectionType ActiveOutputEjectionType);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetExternalResourceProviderSlotsForPlayer(AAstroCharacter* controllingPlayer);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetConverterWantsToBeActive(bool Active);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityIncrementSelectedOutputItemTypeIndex(bool AllowIndexWrapping);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleItemComponentChanged();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    EItemConverterState AuthorityGetItemConverterState() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityDecrementSelectedOutputItemTypeIndex(bool AllowIndexWrapping);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCancelActiveConversions();
    
};

