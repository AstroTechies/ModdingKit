#include "MiniPlanetDefinitions.h"
#include "Templates/SubclassOf.h"

UMiniPlanetDefinitions::UMiniPlanetDefinitions() {
}

int32 UMiniPlanetDefinitions::GetNumMiniPlanets() const {
    return 0;
}

int32 UMiniPlanetDefinitions::GetMiniPlanetIndex(const TSubclassOf<AMiniPlanet> MiniPlanetClass) {
    return 0;
}

FMiniPlanetDefinition UMiniPlanetDefinitions::GetMiniPlanetDefinition(int32 Index) {
    return FMiniPlanetDefinition{};
}


