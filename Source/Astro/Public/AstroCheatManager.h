#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CheatManager -FallbackName=CheatManager
#include "GameFramework/CheatManager.h"
#include "AstroCheatManager.generated.h"

UCLASS(Blueprintable, Within=PlayController)
class ASTRO_API UAstroCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
    UAstroCheatManager();
    UFUNCTION(Exec)
    void ToggleStreamingPowerDebugVis();
    
    UFUNCTION(Exec)
    void ToggleSelectionOutline();
    
    UFUNCTION(Exec)
    void ToggleDrillUI();
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRevealGateStation() const;
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerResetResearchUnlocks() const;
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerResetResearchPoints() const;
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerPlayOutroCinematic() const;
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerGrantResearchPoints(int32 numResearchPoints) const;
    
public:
    UFUNCTION(Exec)
    void AstroToggleWorldUI();
    
    UFUNCTION(Exec)
    void AstroToggleHUD();
    
    UFUNCTION(Exec)
    void AstroToggle2DUI();
    
    UFUNCTION(Exec)
    void AstroRevealGateStation() const;
    
    UFUNCTION(Exec)
    void AstroResetResearchUnlocks() const;
    
    UFUNCTION(Exec)
    void AstroResetResearchPoints() const;
    
    UFUNCTION(Exec)
    void AstroResetNumTimesCreativeTutorialShown() const;
    
    UFUNCTION(Exec)
    void AstroResetNumTimesAdventureTutorialShown() const;
    
    UFUNCTION(Exec)
    void AstroResetEarnedItemDrivePhysicalRewards();
    
    UFUNCTION(Exec)
    void AstroPlayOutroCinematic() const;
    
    UFUNCTION(Exec)
    void AstroGrantResearchPoints(int32 numResearchPoints) const;
    
    UFUNCTION(Exec)
    void AstroFindVintageProbe();
    
    UFUNCTION(Exec)
    void AstroDebugFakeDeadlockAndCrash();
    
    UFUNCTION(Exec)
    void AstroDebugDisableMultiplayer();
    
    UFUNCTION(Exec)
    void AstroAllProbesSpawnWandererRealityTear(bool bAlwaysSpawn) const;
    
};

