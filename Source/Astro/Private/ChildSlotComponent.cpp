#include "ChildSlotComponent.h"
#include "Templates/SubclassOf.h"

UChildSlotComponent::UChildSlotComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ChildSlotClass = NULL;
    this->SlottableItemsFiltrationList = NULL;
    this->SlottableItemsFiltrationListBehavior = ESlottableItemsFiltrationListBehavior::Ignore;
    this->AcceptInputItems = true;
    this->bIgnoreDuringSlotOrgRules = false;
    this->SlotVisible = true;
    this->Unclickable = false;
    this->Breakable = false;
    this->ConnectionPullAllowed = true;
    this->HideConnectorOnPull = true;
    this->GeneratesNoCollision = false;
    this->AllowBodySlotAttach = false;
    this->WeldItems = true;
    this->bSpawnStartingPhysicalItemPackaged = false;
    this->AuxSlotType = EAuxSlotType::None;
    this->ConnectorType = ESlotConnectorType::Plug;
    this->Configuration = ESlotConfiguration::Vertical;
    this->StartingItemType = NULL;
    this->StartingPhysicalItemType = NULL;
    this->StartingItemList = NULL;
    this->StartingActorList = NULL;
    this->StartingRewardSelection = NULL;
}

void UChildSlotComponent::SetChildSlotClass(TSubclassOf<AItemSlot> InClass) {
}

FSlotReference UChildSlotComponent::MakeReference() {
    return FSlotReference{};
}


