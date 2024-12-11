#include "ReplicatedPrinterState.h"

FReplicatedPrinterState::FReplicatedPrinterState() {
    this->CurrentBlueprintItem = NULL;
    this->CurrentBlueprintItemBeingPrinted = NULL;
    this->VisualProgress = 0.00f;
    this->ModifiedProductionRate = 0.00f;
    this->RowIndexAmongVisibleBlueprints = 0;
    this->TotalNumVisibleBlueprintRows = 0;
    this->SelectableRowsBitFlags = 0;
    this->ColumnIndexAmongVisibleBlueprints = 0;
    this->TotalNumVisibleBlueprintColumns = 0;
    this->SelectableColumnsBitFlags = 0;
    this->bCanPrint = false;
    this->bCanUse = false;
    this->bCharging = false;
    this->bPrinting = false;
    this->bOutputSlotFree = false;
    this->bHideIndicator = false;
    this->bControlPanelEngaged = false;
}

