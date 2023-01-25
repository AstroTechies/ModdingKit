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
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleStreamingPowerDebugVis();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleSelectionOutline();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDrillUI();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRevealGateStation() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerResetResearchUnlocks() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerResetResearchPoints() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayOutroCinematic() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGrantResearchPoints(int32 numResearchPoints) const;
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void AstroToggleWorldUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroToggleHUD();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroToggle2DUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroRevealGateStation() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetResearchUnlocks() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetResearchPoints() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetNumTimesCreativeTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetNumTimesAdventureTutorialShown() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroResetEarnedItemDrivePhysicalRewards();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroPlayOutroCinematic() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroGrantResearchPoints(int32 numResearchPoints) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroFindVintageProbe();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroDebugFakeDeadlockAndCrash();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroDebugDisableMultiplayer();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AstroAllProbesSpawnWandererRealityTear(bool bAlwaysSpawn) const;
    
};

