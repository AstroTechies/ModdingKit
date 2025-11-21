#include "AstroCheatManager.h"

UAstroCheatManager::UAstroCheatManager() {
}

void UAstroCheatManager::ToggleStreamingPowerDebugVis() {
}

void UAstroCheatManager::ToggleSelectionOutline() {
}

void UAstroCheatManager::ToggleDrillUI() {
}

void UAstroCheatManager::TestThemeDeactivation(const FString& ThemeName) {
}

void UAstroCheatManager::TestThemeActivation(const FString& ThemeName) {
}

void UAstroCheatManager::TestEventDeactivation(const FString& EventName) {
}

void UAstroCheatManager::TestEventActivation(const FString& EventName, const FString& ThemeName, const FString& missionName) {
}

void UAstroCheatManager::ShowGameMenuMarketingWidget(const FString& warningName) {
}

void UAstroCheatManager::SetCurrentPlayfabFailureReason(const FString& failureReason) {
}

void UAstroCheatManager::ServerSlomo_Implementation(float inNewSpeed) const {
}
bool UAstroCheatManager::ServerSlomo_Validate(float inNewSpeed) {
    return true;
}

void UAstroCheatManager::ServerRevealOrbitalPlatform_Implementation(const bool bShouldPlayCutscene) const {
}
bool UAstroCheatManager::ServerRevealOrbitalPlatform_Validate(const bool bShouldPlayCutscene) {
    return true;
}

void UAstroCheatManager::ServerRevealGateStation_Implementation() const {
}
bool UAstroCheatManager::ServerRevealGateStation_Validate() {
    return true;
}

void UAstroCheatManager::ServerResetResearchUnlocks_Implementation() const {
}
bool UAstroCheatManager::ServerResetResearchUnlocks_Validate() {
    return true;
}

void UAstroCheatManager::ServerResetResearchPoints_Implementation() const {
}
bool UAstroCheatManager::ServerResetResearchPoints_Validate() {
    return true;
}

void UAstroCheatManager::ServerPrinterSimplifyMegastructureRecipe_Implementation(int32 Mode) {
}

void UAstroCheatManager::ServerPlayOutroCinematic_Implementation() const {
}
bool UAstroCheatManager::ServerPlayOutroCinematic_Validate() {
    return true;
}

void UAstroCheatManager::ServerMoveOrbitalPlatformToOtherPlanet_Implementation(const EPlanetIdentifier inPlanetId) const {
}
bool UAstroCheatManager::ServerMoveOrbitalPlatformToOtherPlanet_Validate(const EPlanetIdentifier inPlanetId) {
    return true;
}

void UAstroCheatManager::ServerGrantResearchPoints_Implementation(int32 numResearchPoints) const {
}
bool UAstroCheatManager::ServerGrantResearchPoints_Validate(int32 numResearchPoints) {
    return true;
}

void UAstroCheatManager::OverrideEventData(const FString& titleData) {
}

void UAstroCheatManager::MulticastPrinterSimplifyMegastructureRecipe_Implementation(int32 Mode) {
}

void UAstroCheatManager::LogPlayerSegments() {
}

void UAstroCheatManager::HideGameMenuMarketingWidget(const FString& warningName) {
}

void UAstroCheatManager::CrashClient() {
}

void UAstroCheatManager::AstroToggleWorldUI() {
}

void UAstroCheatManager::AstroToggleHUD() {
}

void UAstroCheatManager::AstroToggle2DUI() {
}

void UAstroCheatManager::AstroSlomo(float inNewSpeed) const {
}

void UAstroCheatManager::AstroShowFullscreenMotD(bool forceDisplay) {
}

void UAstroCheatManager::AstroSetStormsMissionBlocked(bool enableStorms) {
}

void UAstroCheatManager::AstroSetStormsEnabled(bool enableStorms) {
}

void UAstroCheatManager::AstroSetStormImmunity(bool isImmune) {
}

void UAstroCheatManager::AstroSetHackedGatewayCompleteCount(int32 planetID, int32 Count) {
}

void UAstroCheatManager::AstroRevealOrbitalPlatform(const bool bShouldPlayCutscene) const {
}

void UAstroCheatManager::AstroRevealGateStation() const {
}

void UAstroCheatManager::AstroResetResearchUnlocks() const {
}

void UAstroCheatManager::AstroResetResearchPoints() const {
}

void UAstroCheatManager::AstroResetNumTimesGlitchwalkersTutorialShown() const {
}

void UAstroCheatManager::AstroResetNumTimesCreativeTutorialShown() const {
}

void UAstroCheatManager::AstroResetNumTimesAdventureTutorialShown() const {
}

void UAstroCheatManager::AstroResetFullscreenMotDViewData(bool resetLatestTitleNewsData) {
}

void UAstroCheatManager::AstroResetEarnedItemDrivePhysicalRewards() {
}

void UAstroCheatManager::AstroRemovePlayerSegment(const FString& SegmentId) {
}

void UAstroCheatManager::AstroPrinterSimplifyMegastructureRecipe(int32 Mode) {
}

void UAstroCheatManager::AstroPlayOutroCinematic() const {
}

void UAstroCheatManager::AstroOverrideGlitchWalkersEngagementState(int32 StateId) {
}

void UAstroCheatManager::AstroMoveOrbitalPlatformToOtherPlanet(const EPlanetIdentifier inPlanetId) const {
}

void UAstroCheatManager::AstrologGlitchWalkersEngagementState() {
}

void UAstroCheatManager::AstroListScannables() {
}

void UAstroCheatManager::AstroHideFullscreenMotD() {
}

void UAstroCheatManager::AstroGrantResearchPoints(int32 numResearchPoints) const {
}

void UAstroCheatManager::AstroGlitchWalkersFinalEncounterStart() {
}

void UAstroCheatManager::AstroGlitchWalkersFinalEncounterReset() {
}

void UAstroCheatManager::AstroGlitchWalkersFinalEncounterForceComplete() {
}

void UAstroCheatManager::AstroFindVintageProbe() {
}

void UAstroCheatManager::AstroFindEXOVault() {
}

void UAstroCheatManager::AstroFindClosestStorm() {
}

void UAstroCheatManager::AstroFindActorsWithTag(FName Tag) {
}

void UAstroCheatManager::AstroDebugFakeDeadlockAndCrash() {
}

void UAstroCheatManager::AstroDebugDisableMultiplayer() {
}

void UAstroCheatManager::AstroClearGlitchWalkersEngagementState() {
}

void UAstroCheatManager::AstroCheckDlc(UObject* WorldContextObject) {
}

void UAstroCheatManager::AstroAllProbesSpawnWandererRealityTear(bool bAlwaysSpawn) const {
}

void UAstroCheatManager::AstroAddPlayerSegment(const FString& SegmentId, const FString& segmentName, const FString& segmentABParent) {
}


