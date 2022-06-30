#include "AstroDatumContainer.h"

FAstroDatumRef UAstroDatumContainer::MakeDatumRef_DO_NOT_USE_FROM_CPP(const FAstroDatum& Datum) {
    return FAstroDatumRef{};
}

bool UAstroDatumContainer::IsDatumRefValid_DO_NOT_USE_FROM_CPP(FAstroDatumRef DatumRef) {
    return false;
}

UAstroDatumContainer::UAstroDatumContainer() {
}

