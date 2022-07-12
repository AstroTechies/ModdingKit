#include "ActorItemConverterComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UItemType;
class APhysicalItem;
class AAstroCharacter;

void UActorItemConverterComponent::OnReplicationDataChanged() {
}

void UActorItemConverterComponent::OnAuthorityRemovedActiveItemConversion(const FActiveItemConversion& activeConversion) {
}

void UActorItemConverterComponent::OnAuthorityAddedActiveItemConversion(const FActiveItemConversion& activeConversion) {
}

bool UActorItemConverterComponent::IsItemConversionRecipeInputStatusValid(const FItemConversionRecipeInputStatus& ItemConversionRecipeInputStatus) {
    return false;
}

bool UActorItemConverterComponent::IsItemConversionInputItemStatusValid(const FItemConversionInputItemStatus& ItemConversionIngredientStatus) {
    return false;
}

void UActorItemConverterComponent::HandleItemChangedInResourceSlot(APhysicalItem* changedItem) {
}

bool UActorItemConverterComponent::GetShouldLoopProduction() {
    return false;
}

FRecipe UActorItemConverterComponent::GetSelectedOutputRecipe() const {
    return FRecipe{};
}

TSubclassOf<UItemType> UActorItemConverterComponent::GetSelectedOutputItemType() const {
    return NULL;
}

FItemConversionRecipeInputStatus UActorItemConverterComponent::GetConversionRecipeInputStatus(const FRecipe& Recipe) const {
    return FItemConversionRecipeInputStatus{};
}

void UActorItemConverterComponent::AuthoritySetShouldLoopProduction(bool ShouldLoopProduction) {
}

void UActorItemConverterComponent::AuthoritySetSelectedOutputItemTypeIndex(int32 newIndex) {
}

void UActorItemConverterComponent::AuthoritySetOutputEjectionType(EOutputEjectionType ActiveOutputEjectionType) {
}

void UActorItemConverterComponent::AuthoritySetExternalResourceProviderSlotsForPlayer(AAstroCharacter* controllingPlayer) {
}

void UActorItemConverterComponent::AuthoritySetConverterWantsToBeActive(bool Active) {
}

void UActorItemConverterComponent::AuthorityIncrementSelectedOutputItemTypeIndex(bool AllowIndexWrapping) {
}

void UActorItemConverterComponent::AuthorityHandleItemComponentChanged() {
}

EItemConverterState UActorItemConverterComponent::AuthorityGetItemConverterState() const {
    return EItemConverterState::Inactive;
}

void UActorItemConverterComponent::AuthorityDecrementSelectedOutputItemTypeIndex(bool AllowIndexWrapping) {
}

void UActorItemConverterComponent::AuthorityCancelActiveConversions() {
}

void UActorItemConverterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorItemConverterComponent, ReplicationData);
}

UActorItemConverterComponent::UActorItemConverterComponent() {
    this->ConversionFormulaType = NULL;
    this->OutputItemTypeList = NULL;
    this->MinPowerUnitProductionTime = 60.00f;
    this->MaxPowerUnitProductionTime = 15.00f;
    this->DefaultOutputEjectionType = EOutputEjectionType::None;
    this->OutputItemEjectionForce = 25000.00f;
    this->InputSlotsOrganizationRuleType = EInputManagementType::None;
    this->bCannotProcessConversionsInParallel = false;
    this->bShouldLoopProduction = false;
    this->bInputSlotsAreUnclickable = false;
    this->bOutputSlotIsUnclickable = true;
    this->bDetonatesVolatileInputItems = false;
    this->bShowOutputIndicatorsWhenSelectingRecipe = false;
    this->bForceRecipeSelection = false;
    this->bCanUseActorItemComponentAsInput = false;
    this->bProduceOutputsToUniqueSlots = false;
    this->bKeepPartialOutputBetweenSaves = false;
    this->bRefundInputResourcesOnCancel = false;
    this->bIgnoresPower = false;
}

