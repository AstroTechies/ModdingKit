#include "AstroCharacterHat.h"

UAstroCharacterHat::UAstroCharacterHat() {
    this->AcceptSuitColors = false;
    this->AcceptSuitMaterial = true;
    this->HatCategory = ECharacterHatCategory::Head;
}

FCharacterHatPerSuitModifiers UAstroCharacterHat::GetHatModifierForSuit(UAstroCharacterSuit* Suit, bool allowSuitSpecificOverrides) const {
    return FCharacterHatPerSuitModifiers{};
}

void UAstroCharacterHat::ApplyToMesh(UStaticMeshComponent* targetMesh, UAstroCharacterSuit* Suit, UAstroCharacterHat* hatDef, UAstroCharacterPalette* Palette, bool bObfuscated, UMaterialInterface* ObfuscatedMaterial) {
}


