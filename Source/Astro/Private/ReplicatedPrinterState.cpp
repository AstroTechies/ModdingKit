#include "ReplicatedPrinterState.h"

FReplicatedPrinterState::FReplicatedPrinterState() {
    this->CurrentBlueprintItem = NULL;
    this->CurrentBlueprintItemBeingPrinted = NULL;
    this->VisualProgress = 0.00f;
    this->ModifiedProductionRate = 0.00f;
    this->IndexAmongUnlockedBlueprints = 0;
    this->TotalNumUnlockedBlueprints = 0;
    this->bCanPrint = false;
    this->bCanUse = false;
    this->bCharging = false;
    this->bPrinting = false;
    this->bOutputSlotFree = false;
    this->bHideIndicator = false;
    this->bControlPanelEngaged = false;
}

