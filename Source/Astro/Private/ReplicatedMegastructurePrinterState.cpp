#include "ReplicatedMegastructurePrinterState.h"

FReplicatedMegastructurePrinterState::FReplicatedMegastructurePrinterState() {
    this->CurrentSelectedTier = 0;
    this->CurrentPrintingTier = 0;
    this->SatisfiedTier = 0;
    this->HasPrintedFinalTier = false;
}

