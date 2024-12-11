#include "AstroEntityWorld.h"

UAstroEntityWorld::UAstroEntityWorld() {
    this->EntityContainer = NULL;
}

void UAstroEntityWorld::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

FAstroDatumRef UAstroEntityWorld::GetOwnerEntity(FAstroDatumRef EntityComponentRef, bool& bOutSuccess) {
    return FAstroDatumRef{};
}

FAstroDatumRef UAstroEntityWorld::GetEntityRootComponentRef(FAstroDatumRef EntityRef, bool& bOutSuccess) {
    return FAstroDatumRef{};
}

FAstroDatumRef UAstroEntityWorld::GetEntityComponentRefByName(FAstroDatumRef EntityRef, FName ComponentName, bool& bOutSuccess) {
    return FAstroDatumRef{};
}

TArray<FAstroDatumRef> UAstroEntityWorld::GetEntityComponentDatumRefs(FAstroDatumRef EntityRef, bool& bOutSuccess) {
    return TArray<FAstroDatumRef>();
}


