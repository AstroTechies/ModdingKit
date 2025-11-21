#include "MegastructureManager.h"

UMegastructureManager::UMegastructureManager() {
    this->bHasCachedMuseumState = false;
}

bool UMegastructureManager::RemoveMegastructure(AMegaStructure* inMegastructure) {
    return false;
}

bool UMegastructureManager::RemoveBuildingPlatform(APhysicalItem* inBuildingPlatform, const EMegastructureType inMegastructureType) {
    return false;
}

bool UMegastructureManager::RemoveAnchor(APhysicalItem* inAnchor, const EMegastructureType inAnchorType) {
    return false;
}

void UMegastructureManager::RegisterBuildingPlatform(APhysicalItem* inBuildingPlatform, const EMegastructureType inMegastructureType) {
}

void UMegastructureManager::RegisterAnchor(APhysicalItem* inAnchor, const EMegastructureType inAnchorType) {
}

bool UMegastructureManager::IsMegastructureOfTypeOnPlanet(const EMegastructureType inMegastructureType, const EPlanetIdentifier inPlanetId) const {
    return false;
}

bool UMegastructureManager::IsMegastructureOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const {
    return false;
}

bool UMegastructureManager::IsBuildingPlatformOfTypeOnPlanet(const EMegastructureType inMegastructureType, const EPlanetIdentifier inPlanetId) const {
    return false;
}

bool UMegastructureManager::IsBuildingPlatformOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const {
    return false;
}

bool UMegastructureManager::IsAnchorOfTypeOnPlanet(const EMegastructureType inAnchorType, const EPlanetIdentifier inPlanetId) const {
    return false;
}

bool UMegastructureManager::IsAnchorOfTypeInSolarSystem(const EMegastructureType inAnchorType) const {
    return false;
}

AMegaStructure* UMegastructureManager::GetUniqueMegastructureOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const {
    return NULL;
}

APhysicalItem* UMegastructureManager::GetUniqueAnchorOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const {
    return NULL;
}

int32 UMegastructureManager::GetMegastructuresCountOfType(const EMegastructureType inMegastructureType) const {
    return 0;
}

AMegaStructure* UMegastructureManager::GetMegastructureOfTypeOnPlanet(const EMegastructureType inMegastructureType, const EPlanetIdentifier inPlanetId) const {
    return NULL;
}

int32 UMegastructureManager::GetMaxAllowedMegastructuresOfType(const EMegastructureType inMegastructureType) {
    return 0;
}

int32 UMegastructureManager::GetBuildingPlatformsCountOfType(const EMegastructureType inMegastructureType) const {
    return 0;
}

APhysicalItem* UMegastructureManager::GetAnchorOfTypeOnPlanet(const EMegastructureType inAnchorType, const EPlanetIdentifier inPlanetId) const {
    return NULL;
}


