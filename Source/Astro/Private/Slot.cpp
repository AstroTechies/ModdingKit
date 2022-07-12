#include "Slot.h"

FSlot::FSlot() {
    this->SlotTemplate = NULL;
    this->slotType = ESlotType::Power;
    this->ConnectorType = ESlotConnectorType::Plug;
    this->SlotTier = 0;
    this->SlotBinaryTreeDepth = 0;
    this->SlotTierCount = 0;
    this->Breakable = false;
    this->IsReserved = false;
    this->Configuration = ESlotConfiguration::Vertical;
    this->PositionType = ESlotPosition::RelativeTransform;
    this->StartingItemType = NULL;
    this->StartingPhysicalItemType = NULL;
    this->StartingItemList = NULL;
    this->StartingActorList = NULL;
    this->StartingRewardSelection = NULL;
    this->bSpawnStartingPhysicalItemPackaged = false;
    this->ConnectionClass = NULL;
    this->NumberOfRotations = ENumRotations::One;
    this->bIsBodySlot = false;
    this->bAllowBodySlotAttach = false;
    this->bGenerateNoCollision = false;
    this->bCanHoldItem = false;
    this->bItemBlocksConnection = false;
    this->bConnectionBlocksItem = false;
    this->bNoConnectionPull = false;
    this->bSingleConnection = false;
    this->bHideConnectorOnPull = false;
    this->bConnectionTense = false;
    this->bUnclickable = false;
    this->bAlwaysCountsForFullness = false;
    this->bIsManagedByRule = false;
    this->bHasExternallyManagedConnection = false;
    this->bCanAcceptUnslottableItems = false;
    this->bIsTrailerHitch = false;
    this->bPowerIncomingOnly = false;
    this->bStreamingPowerConnectionsMergeNodes = false;
    this->bWeldItems = false;
    this->AuxSlotType = EAuxSlotType::None;
    this->TraceRadius = 0.00f;
    this->IndicatorScale = 0.00f;
    this->SlottableItemsFiltrationList = NULL;
    this->SlottableItemsFiltrationListBehavior = ESlottableItemsFiltrationListBehavior::Ignore;
    this->SlotTooltipComponent = NULL;
    this->SlotResourceInfo = NULL;
    this->TracePrimitive = NULL;
    this->PositionComponent = NULL;
    this->Owner = NULL;
    this->OwnerRule = NULL;
    this->BuildingConnection = NULL;
    this->Delegates = NULL;
}

