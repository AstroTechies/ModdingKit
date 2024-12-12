#include "AstroVisorMaterial.h"

UAstroVisorMaterial::UAstroVisorMaterial() {
    this->VisorMaterialInstance = NULL;
}

UMaterialInterface* UAstroVisorMaterial::GetMaterialInstanceForSuit(UAstroCharacterSuit* Suit) const {
    return NULL;
}


