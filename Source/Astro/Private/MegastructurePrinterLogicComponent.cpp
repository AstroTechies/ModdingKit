#include "MegastructurePrinterLogicComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UMegastructurePrinterLogicComponent::UMegastructurePrinterLogicComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->REP_MegastructureItemType = NULL;
    this->REP_PrintedMegastructure = NULL;
    this->REP_bIsMegastructureProductionModeEnabled = false;
    this->MegastructureItemTypeCDO = NULL;
}

void UMegastructurePrinterLogicComponent::OnSlotEvent(APhysicalItem* inItem) {
}

void UMegastructurePrinterLogicComponent::OnRep_PrintedMegastructure() {
}

void UMegastructurePrinterLogicComponent::OnRep_MegastructurePrinterStateAtomic(FReplicatedMegastructurePrinterState prevState) {
}

void UMegastructurePrinterLogicComponent::OnRep_MegastructureItemType() {
}

void UMegastructurePrinterLogicComponent::OnRep_IsInMegastructureProductionMode() {
}

void UMegastructurePrinterLogicComponent::OnItemUnslotted(APhysicalItem* inItem) {
}

void UMegastructurePrinterLogicComponent::OnItemSlotted(APhysicalItem* inItem) {
}

void UMegastructurePrinterLogicComponent::K2_BlueprintSaveDataReplicated() {
}

TArray<int32> UMegastructurePrinterLogicComponent::GetTotalItemAmounts() {
    return TArray<int32>();
}

TArray<int32> UMegastructurePrinterLogicComponent::GetConsumedItemAmounts() {
    return TArray<int32>();
}

void UMegastructurePrinterLogicComponent::AuthorityToggleMegastructureProductionMode() {
}

void UMegastructurePrinterLogicComponent::AuthoritySetMegastructureProductionMode(bool bEnabled) {
}

void UMegastructurePrinterLogicComponent::AuthoritySetMegastructureItemType(TSubclassOf<UItemType> ItemType) {
}

void UMegastructurePrinterLogicComponent::AuthorityResetSatisfiedTier(AActor* destroyedMegastructure) {
}

void UMegastructurePrinterLogicComponent::AuthorityHideIndicators() {
}

void UMegastructurePrinterLogicComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UMegastructurePrinterLogicComponent, REP_MegastructureItemType);
    DOREPLIFETIME(UMegastructurePrinterLogicComponent, REP_MegastructurePrinterState);
    DOREPLIFETIME(UMegastructurePrinterLogicComponent, REP_PrintedMegastructure);
    DOREPLIFETIME(UMegastructurePrinterLogicComponent, REP_bIsMegastructureProductionModeEnabled);
}


