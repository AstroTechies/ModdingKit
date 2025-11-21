#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "EPlanetIdentifier.h"
#include "AstroCheatManager.generated.h"

class UObject;

UCLASS(Blueprintable, Within=PlayController)
class ASTRO_API UAstroCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
    UAstroCheatManager();

    UFUNCTION(BlueprintCallable, Exec)
    void ToggleStreamingPowerDebugVis();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleSelectionOutline();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDrillUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestThemeDeactivation(const FString& ThemeName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestThemeActivation(const FString& ThemeName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestEventDeactivation(const FString& EventName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestEventActivation(const FString& EventName, const FString& ThemeName, const FString& missionName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ShowGameMenuMarketingWidget(const FString& warningName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetCurrentPlayfabFailureReason(const FString& failureReason);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSlomo(float inNewSpeed) const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRevealOrbitalPlatform(const bool bShouldPlayCutscene) const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRevealGateStation() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerResetResearchUnlocks() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerResetResearchPoints() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerPrinterSimplifyMegastructureRecipe(int32 Mode);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayOutroCinematic() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerMoveOrbitalPlatformToOtherPlanet(const EPlanetIdentifier inPlanetId) const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGrantResearchPoints(int32 numResearchPoints) const;
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void OverrideEventData(const FString& titleData);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPrinterSimplifyMegastructureRecipe(int32 Mode);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void LogPlayerSegments();
    
    UFUNCTION(BlueprintCallable, Exec)
    void HideGameMenuMarketingWidget(const FString& warningName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CrashClient();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroToggleWorldUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroToggleHUD();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroToggle2DUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroSlomo(float inNewSpeed) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroShowFullscreenMotD(bool forceDisplay);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroSetStormsMissionBlocked(bool enableStorms);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroSetStormsEnabled(bool enableStorms);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroSetStormImmunity(bool isImmune);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroSetHackedGatewayCompleteCount(int32 planetID, int32 Count);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroRevealOrbitalPlatform(const bool bShouldPlayCutscene) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroRevealGateStation() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetResearchUnlocks() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetResearchPoints() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetNumTimesGlitchwalkersTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetNumTimesCreativeTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetNumTimesAdventureTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetFullscreenMotDViewData(bool resetLatestTitleNewsData);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetEarnedItemDrivePhysicalRewards();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroRemovePlayerSegment(const FString& SegmentId);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroPrinterSimplifyMegastructureRecipe(int32 Mode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroPlayOutroCinematic() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroOverrideGlitchWalkersEngagementState(int32 StateId);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroMoveOrbitalPlatformToOtherPlanet(const EPlanetIdentifier inPlanetId) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstrologGlitchWalkersEngagementState();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroListScannables();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroHideFullscreenMotD();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroGrantResearchPoints(int32 numResearchPoints) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroGlitchWalkersFinalEncounterStart();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroGlitchWalkersFinalEncounterReset();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroGlitchWalkersFinalEncounterForceComplete();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroFindVintageProbe();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroFindEXOVault();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroFindClosestStorm();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroFindActorsWithTag(FName Tag);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroDebugFakeDeadlockAndCrash();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroDebugDisableMultiplayer();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroClearGlitchWalkersEngagementState();
    
    UFUNCTION(BlueprintCallable, Exec, meta=(WorldContext="WorldContextObject"))
    void AstroCheckDlc(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroAllProbesSpawnWandererRealityTear(bool bAlwaysSpawn) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroAddPlayerSegment(const FString& SegmentId, const FString& segmentName, const FString& segmentABParent);
    
};

