#include "ItemConverterComponentContainer.h"

UItemConverterComponentContainer::UItemConverterComponentContainer() {
}

FItemConverterComponent UItemConverterComponentContainer::GetItemConverterComponent(FAstroDatumRef ItemConverterComponentRef, bool& bOutSuccess) {
    return FItemConverterComponent{};
}

FItemConverterComponent UItemConverterComponentContainer::FindItemConverterComponent(FAstroDatumRef EntityRef, bool& bOutSuccess) {
    return FItemConverterComponent{};
}


