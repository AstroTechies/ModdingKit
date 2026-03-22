#include "BreadboardPrinterAnimationReplicationData.h"

FBreadboardPrinterAnimationReplicationData::FBreadboardPrinterAnimationReplicationData() {
    this->bPrinterIsAvailable = false;
    this->bPreviewIsEnabled = false;
    this->bPrintingIsProgressing = false;
    this->PrintSpeed = 0.00f;
    this->PrintheadHeight = 0.00f;
    this->PrintheadExtension = 0.00f;
}

