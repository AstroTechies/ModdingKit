#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EnableSignalDelegate.h"
#include "Recipe.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OnItemConversionCompleteDelegate.h"
#include "OnItemConverterActiveConversionsListChangedDelegate.h"
#include "ItemConversionInputItemStatus.h"
#include "OnItemConverterStateChangedDelegate.h"
#include "EOutputEjectionType.h"
#include "ItemConverterReplicationData.h"
#include "EInputManagementType.h"
#include "SlotReference.h"
#include "ActiveItemConversion.h"
#include "ItemConversionRecipeInputStatus.h"
#include "EItemConverterState.h"
#include "ActorItemConverterComponent.generated.h"

class UItemConversionFormula;
class UItemList;
class URecipeOrganizationRule;
class UOutputOrganizationRule;
class APhysicalItem;
class UItemType;
class AAstroCharacter;

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
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicationDataChanged, meta=(AllowPrivateAccess=true))
    FItemConverterReplicationData ReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemConverterReplicationData PrevReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlotRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> OutputSlotRefs;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<URecipeOrganizationRule> RecipeOrganizationRule;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<UOutputOrganizationRule> OutputOrganizationRule;
    
public:
    UActorItemConverterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION()
    void OnReplicationDataChanged();
    
    UFUNCTION()
    void OnAuthorityRemovedActiveItemConversion(const FActiveItemConversion& activeConversion);
    
    UFUNCTION()
    void OnAuthorityAddedActiveItemConversion(const FActiveItemConversion& activeConversion);
    
    UFUNCTION(BlueprintPure)
    static bool IsItemConversionRecipeInputStatusValid(const FItemConversionRecipeInputStatus& ItemConversionRecipeInputStatus);
    
    UFUNCTION(BlueprintPure)
    static bool IsItemConversionInputItemStatusValid(const FItemConversionInputItemStatus& ItemConversionIngredientStatus);
    
protected:
    UFUNCTION()
    void HandleItemChangedInResourceSlot(APhysicalItem* changedItem);
    
public:
    UFUNCTION(BlueprintPure)
    bool GetShouldLoopProduction();
    
    UFUNCTION(BlueprintPure)
    FRecipe GetSelectedOutputRecipe() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetSelectedOutputItemType() const;
    
    UFUNCTION(BlueprintPure)
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

