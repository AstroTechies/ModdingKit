#include "LRD.h"

ALRD::ALRD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

ELRDType ALRD::GetLRDType_Implementation() {
    return ELRDType::None;
}


