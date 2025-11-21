#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "CloudsEnabledUpdatedDelegate.h"
#include "EPlanetIdentifier.h"
#include "OnBeginTransitionSequenceDelegate.h"
#include "SignalDelegate.h"
#include "SolarBody.h"
#include "Templates/SubclassOf.h"
#include "VendingMachineInterface.h"
#include "OrbitalPlatform.generated.h"

class AActor;
class AMiniPlanet;
class APhysicalItem;
class ATrueFlatPlatform;
class UClickableComponent;
class USceneComponent;
class USphereComponent;
class UStaticMeshComponent;
class UTooltipComponent;

UCLASS(Blueprintable)
class ASTRO_API AOrbitalPlatform : public ASolarBody, public IVendingMachineInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStageChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnNewMiniPlanetRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnNewMiniPlanetSeedReceived;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnNewMiniPlanetFullySpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCloudsEnabledUpdated OnCloudsEnabledUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOrbitalPlatformMovedToNewPlanet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBeginTransitionSequence OnBeginTransitionSequence;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlaySpawnCutscene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PlatformMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ClickCollisionSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ProxyMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ProxyRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APhysicalItem>> VendingMachineBlueprints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProxyMeshScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator OrbitalRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OrbitDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OrbitingAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OrbitingPlanetUpdated, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier REP_OrbitingPlanetIdentifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_StageChanged, meta=(AllowPrivateAccess=true))
    int32 REP_Stage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MiniPlanetClassUpdated, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMiniPlanet> REP_MiniPlanetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AMiniPlanet* MiniPlanetActorRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMiniPlanet* PendingDeleteMiniPlanetRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ATrueFlatPlatform*> TrueFlatPlatforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CloudsEnabledUpdated, meta=(AllowPrivateAccess=true))
    uint8 REP_bCloudsEnabled: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasCreativeFlightEnabled: 1;
    
public:
    AOrbitalPlatform(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetVoxelsVisibility(bool bIsVisible, bool bForceUpdate);
    
    UFUNCTION(BlueprintCallable)
    void SetPlanetSelection(const bool bInEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetMeshVisibility(bool bIsVisible);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool RemoveTrueFlatPlatform(ATrueFlatPlatform* inTFP);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveActualVisibilityChanged(bool bIsVisible);
    
    UFUNCTION(BlueprintCallable)
    void OnSolarBodyClick(ASolarBody* inSolarBody);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_StageChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_OrbitingPlanetUpdated();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MiniPlanetClassUpdated();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CloudsEnabledUpdated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInitializeLandingZones();
    
    UFUNCTION(BlueprintCallable)
    void OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed);
    
private:
    UFUNCTION(BlueprintCallable)
    void K2_MiniPlanetVFXOpened();
    
    UFUNCTION(BlueprintCallable)
    void K2_MiniPlanetVFXEnclosed();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ATrueFlatPlatform*> GetTrueFlatPlatfroms() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTerrainNormal(const FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentStage() const;
    
private:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityToggleClouds();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetMiniPlanetClass(TSubclassOf<AMiniPlanet> MiniPlanetClass);
    
public:
    UFUNCTION(BlueprintCallable)
    void AuthoritySetCreativeFlightEnabled(const bool bInIsEnabled);
    
private:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetCloudsEnabled(bool bEnabled);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityMoveOrbitalPlatformToOtherPlanet(const EPlanetIdentifier inPlanetIdentifier);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityIncrementStage();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddTrueFlatPlatform(ATrueFlatPlatform* inTFP);
    

    // Fix for true pure virtual functions not being implemented
};

