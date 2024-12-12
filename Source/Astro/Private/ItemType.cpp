#include "ItemType.h"

UItemType::UItemType() {
    this->bDestroyOnAddDeformation = true;
    this->Indestructible = false;
    this->IsVolatile = false;
    this->IsPower = false;
    this->IsOxygen = false;
    this->CreativeSpawnEmpty = false;
    this->UseSquareIconBackground = false;
    this->bCanBeScrapped = false;
    this->bApplyTintToHarvestActors = true;
    this->bIsUnrepackageable = false;
    this->InternalStorageBehavior = EItemStorageBehavior::None;
    this->ItemRepackageAudioSwitch = TEXT("Default");
    this->TerrainCollectionMultiplier = 1.00f;
    this->TerrainCollectionMesh = NULL;
    this->TerrainVolumeMesh = NULL;
    this->PickupActor = NULL;
    this->DefaultContainerType = NULL;
    this->UnbundleType = NULL;
    this->BundleType = NULL;
    this->DefaultContainerIndicatorType = NULL;
    this->AstropediaResourceType = EAstroGameMenuTutoriaSlideCardKey::Invalid;
    this->bHasAltConstructionRecipe = false;
    this->CatalogData = NULL;
    this->ResearchSubjectDefinition = NULL;
    this->CrateOverlayTexture = NULL;
    this->WidgetIcon = NULL;
}

FRecipe UItemType::GetConstructionRecipe() const {
    return FRecipe{};
}


