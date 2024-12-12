#include "AstroGameSingleton.h"

UAstroGameSingleton::UAstroGameSingleton() {
    this->bIsExperimentalBuild = false;
    this->GameMenu = NULL;
    this->TutorialSlideDeckDatabase = NULL;
    this->DefaultPopoutWrapper = NULL;
    this->HelpMenu = NULL;
    this->HelpMenuGamepad = NULL;
    this->DebugMenu = NULL;
    this->CinematicMenu = NULL;
    this->GameplayGlobals = NULL;
    this->MasterItemList = NULL;
    this->ForcedPackageIncludes = NULL;
    this->ResearchProgressionTable = NULL;
    this->EmoteTable = NULL;
    this->SuitTable = NULL;
    this->DeployableItemPackageCatalog = NULL;
    this->DestructionDefinitionTable = NULL;
    this->ScrapItemType = NULL;
    this->SedimentItemType = NULL;
    this->NuggetBaseClass = NULL;
    this->ScrapConversionTable = NULL;
    this->SoilConversionTable = NULL;
    this->ItemTradeValueTable = NULL;
    this->CraftingSources = NULL;
    this->InputKeyToIconMapping = NULL;
    this->DiscreteAstroInputDefinitionDatabase = NULL;
    this->TetherProperties = NULL;
    this->FoliageDestructionData = NULL;
    this->WindPowerActivationThreshold = 0.00f;
    this->DefaultHoldInputDuration = 0.00f;
    this->DefaultHoldInputCancelTreshold = 0.00f;
    this->CharacterCustomizationGlobals = NULL;
//    this->MicroTxnStoreGlobals = NULL;
    this->RailNetworkType = NULL;
//    this->WindowsSpecificCustomizationContent = NULL;
//    this->XboxSpecificCustomizationContent = NULL;
//    this->PS4SpecificCustomizationContent = NULL;
//    this->SwitchSpecificCustomizationContent = NULL;
    this->PlanetProxyActor = NULL;
    this->WindstormClass = NULL;
    this->RewardTable = NULL;
    this->ControlSymbolIconActor = NULL;
    this->ControlSymbolIconPingActor = NULL;
    this->ResourceInfoActor = NULL;
    this->ResourceInfoNeededActor = NULL;
    this->ResourceInfoPingActor = NULL;
    this->PowerPingActorCharge = NULL;
    this->PowerPingActorDischarge = NULL;
    this->ConnectSymbol = NULL;
    this->PullConnectionSymbol = NULL;
    this->LiftItemSymbol = NULL;
    this->PlaceItemSymbol = NULL;
    this->IndicatorMaterial = NULL;
    this->InvalidIndicatorMaterial = NULL;
    this->ButtonMaterial = NULL;
    this->PrintingMaterial = NULL;
    this->ASTROFONT = NULL;
    this->PowerColdMaterial = NULL;
    this->PowerHotMaterial = NULL;
    this->AstroColorDatabase = NULL;
    this->AstroUIStylingDatabase = NULL;
    this->AstroGlitchwalkersUIStylingDatabase = NULL;
    this->AstroUIAudioDatabase = NULL;
    this->NonFlashingButtonMaterial = NULL;
    this->FlashingButtonMaterial = NULL;
    this->ResourceShellMesh = NULL;
    this->CylinderButtonOuterMesh = NULL;
    this->CylinderButtonInnerMesh = NULL;
    this->CylinderButtonFullMesh = NULL;
    this->BoxButtonOuterMesh = NULL;
    this->BoxButtonInnerMesh = NULL;
    this->BoxButtonFullMesh = NULL;
    this->LocalizationCultureOptions = NULL;
    this->FoliageLUT = NULL;
    this->ResourceObjectTooltipBadgeBackgroundSquare = NULL;
    this->ResourceObjectTooltipBadgeBackgroundRound = NULL;
    this->ToolTipWidget = NULL;
    this->AstroNotificationDatabase = NULL;
    this->AstroPopupBadgeDatabase = NULL;
    this->AstroErrorStringTable = NULL;
    this->PlanetBiomeDisplayNames = NULL;
    this->InteractionIndicatorPip = NULL;
    this->DefaultMessageOfTheDay = NULL;
    this->RequireNintendoLinkAccountMessageOfTheDay = NULL;
    this->AchievementDefinitions = NULL;
    this->CreativeModePaintPalette = NULL;
    this->CreativeModePaintSpecialPaletteIndex = 4294967295;
    this->ActuatorConnection = NULL;
    this->CurrentLTERocket = NULL;
}

UAstroGameSingleton* UAstroGameSingleton::GetAstroGameSingleton() {
    return NULL;
}


