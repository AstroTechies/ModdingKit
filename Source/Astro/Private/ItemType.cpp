#include "ItemType.h"

UItemType::UItemType() {
    // Safe to leave checked 
    this->bDestroyOnAddDeformation = true;
    this->Indestructible = false;
    this->IsVolatile = false;
    this->IsPower = false;
    this->IsOxygen = false;
    this->bIsMegastructure = false;
    this->CreativeSpawnEmpty = false;
    this->DLCEntitlementLock = EItemDLCEntitlementLock::None;
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
    this->MegastructureRecipe = NULL;
    this->bHasAltConstructionRecipe = false;
    this->CatalogData = NULL;
    this->ResearchSubjectDefinition = NULL;
    this->CrateOverlayTexture = NULL;
    this->WidgetIcon = NULL;
}

UMegastructureRecipe* UItemType::GetMegastructureRecipe() const {
    return NULL;
}

FRecipe UItemType::GetConstructionRecipe() const {
    return FRecipe{};
}


