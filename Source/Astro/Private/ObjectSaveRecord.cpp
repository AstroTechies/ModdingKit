#include "ObjectSaveRecord.h"

FObjectSaveRecord::FObjectSaveRecord() {
    this->RuntimeObject = NULL;
    this->Class = NULL;
    this->NameIndex = 0;
    this->Flags = 0;
    this->OuterObjectIndex = 0;
    this->CustomDataOffset = 0;
}

