#include "MegastructureAppendageInfo.h"

FMegastructureAppendageInfo::FMegastructureAppendageInfo() {
    this->AppendageType = MegaStructure;
    this->bShowComponent = false;
    this->StaticMesh = NULL;
    this->SkeletalMesh = NULL;
    this->Actor = NULL;
    this->ItemType = NULL;
}

