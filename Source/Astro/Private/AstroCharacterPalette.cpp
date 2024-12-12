#include "AstroCharacterPalette.h"

UAstroCharacterPalette::UAstroCharacterPalette() {
}

UMaterialInstanceConstant* UAstroCharacterPalette::GetMaterialInstanceForSuit(UAstroCharacterSuit* Suit, bool AllowSuitSpecificMaterialOverrides) const {
    return NULL;
}

FAstroSuitColors UAstroCharacterPalette::GetMaterialColorsForSuit(UAstroCharacterSuit* Suit) const {
    return FAstroSuitColors{};
}


