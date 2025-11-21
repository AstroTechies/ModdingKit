#pragma once
#include "CoreMinimal.h"
#include "AnchorLaunchCheckDelegate.h"
#include "EMegastructureType.h"
#include "EPlanetIdentifier.h"
#include "EWreckState.h"
#include "MegaStructure.h"
#include "OrbitalPlatformTargetSelectedDelegate.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "Wreck.generated.h"

class AActor;
class APhysicalItem;
class ASolarBody;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API AWreck : public AMegaStructure {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ButtonNamePressed, meta=(AllowPrivateAccess=true))
    FString ButtonPressedName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_DestinationLandingPadChanged, meta=(AllowPrivateAccess=true))
    APhysicalItem* destinationLandingPad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> LoadedAnchorItemTypeClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnHandleAnchorLoadUnload;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDestinationLandingPadChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOrbitalPlatformAnchorEjecting;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOrbitalPlatformSpawnBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFinishedOrbitalPlatformSpawn;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOrbitalPlatformTargetSelected OnWantingToSpawnOrbitalPlatform;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnchorLaunchCheck CanAnchorLaunch;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    EWreckState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsInPlanetSelection: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsOPSpawned: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsOPComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TargetOPSpawnPlanetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_OPPlanetIdChanged, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier OPPlanetId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FString, bool> AnchorsToRestock;
    
public:
    AWreck(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetPlanetSelection(const bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetOrbitalPlatformComplete(bool isComplete);
    
    UFUNCTION(BlueprintCallable)
    void SetDestinationLandingPad(APhysicalItem* inDestinationLandingPad);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentState(EWreckState NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonPressedName(const FString& inButtonPressedName);
    
    UFUNCTION(BlueprintCallable)
    void SetAnchorRestockableState(const FString& AnchorName, const bool isRestockable);
    
    UFUNCTION(BlueprintCallable)
    void OnSolarBodyClick(ASolarBody* SolarBody);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_OPPlanetIdChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_DestinationLandingPadChanged() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ButtonNamePressed() const;
    
    UFUNCTION(BlueprintCallable)
    void OnOPSpawned();
    
public:
    UFUNCTION(BlueprintCallable)
    void LaunchAnchor(APhysicalItem* inDestinationLandingPad);
    
    UFUNCTION(BlueprintCallable)
    void HandleOrbitalPlatformSpawn(const EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    void HandleOrbitalPlatformExtraStages();
    
    UFUNCTION(BlueprintCallable)
    void HandleAnchorLoadUnload(const FString& inButtonPressedName);
    
    UFUNCTION(BlueprintCallable)
    void EjectOrbitalPlatformAnchor();
    
    UFUNCTION(BlueprintCallable)
    void CheckAnchorCanLaunch(EMegastructureType megastructureType, APhysicalItem* inDestinationLandingPad);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetEntitledMegaStructureActive();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void AuthorityOrbitalPlatformExtraStages();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityOnOPSpawningSequenceBegin();
    
    UFUNCTION(BlueprintCallable)
    void AddAnchorToRestock(const FString& AnchorName, const bool isRestockable);
    
};

