#include "AstroCustomGameSettings.h"

FAstroCustomGameSettings::FAstroCustomGameSettings() {
    this->FormatVersion = 0;
//    this->ConfigEntryType = FAstroCGMLibraryConfigEntryType::VE_NotSaved;
    this->SkipDropPodLaunchSequence = false;
    this->NoStartingShelter = false;
    this->StartingPlanetId = EPlanetIdentifier::None;
    this->IsGlitchWalkersConfiguration = false;
}

