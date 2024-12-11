#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EAstroPlayerStormRadiusStates.h"
#include "EPlanetIdentifier.h"
#include "PlayerStormEffectsInfo.h"
#include "PlayerStormRadiusStateChangeDelegateDelegate.h"
#include "StormSpawnedLocalPointFXConfig.h"
#include "StormSpawnedLocalPointFXState.h"
#include "Templates/SubclassOf.h"
#include "AstroStorm.generated.h"

class AAstroPlayerController;
class AAstroStormVisualBase;
class UParticleSystem;
class UParticleSystemComponent;

UCLASS(Blueprintable)
class ASTRO_API AAstroStorm : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 StormID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 StateIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Lifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlayerStormEffectsInfo> PlayerStormEffectsInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayEffectsSeconds_LevelZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayEffectsSeconds_LevelOne;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayEffectsSeconds_LevelTwo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayEffectsSeconds_LevelThree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterGameplayRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerGameplayRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerGameplayRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterEdgeFogRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerEdgeFogRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterEyeFogRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerEyeFogRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InStormFogMaxOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EyeFogMaxOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InStormFogDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EyeFogDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerFogRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerGlitchWallApproachDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LocalPointSpawnedFXEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXConfig> SpawnedFXConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UParticleSystem*, int32> SpawnedFXConfigIndexMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SpawnedFXStates, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXState> SpawnedFXStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXState> PrevSpawnedFXStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> ClientSpawnedFXActiveEmitterPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnedFXStatesInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerEnteredStorm;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerExitedStorm;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerEnteredEye;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerExitedEye;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroStormVisualBase* StormVisualActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AAstroStormVisualBase>> StormVisualClasses;
    
    AAstroStorm(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartSpinUpVisualsIfNecessary();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartSpinDownVisualsIfNecessary();
    
private:
    UFUNCTION(BlueprintCallable)
    UParticleSystemComponent* SpawnLocalPointSpawnedFX(UParticleSystem* ParticleTemplate, FVector Position, FTransform SpawnTransform);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetPlayerStormRadiusState(AAstroPlayerController* PlayerController, EAstroPlayerStormRadiusStates State);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayerExitedStorm(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayerEnteredStorm(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    void RegisterPlayerForStormEffectsTracking(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SpawnedFXStates();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlanetVirusProtectionUpdated(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    void OnParticleSystemFinished(UParticleSystemComponent* FinishedComponent);
    
    UFUNCTION(BlueprintCallable)
    bool IsSafeSpawnedFXLocation(FVector Location, float Radius);
    
    UFUNCTION(BlueprintCallable)
    void InitLocalPointSpawnedFXStateContainers();
    
public:
    UFUNCTION(BlueprintCallable)
    bool HasPlayerStormEffectsInfo(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetStormOrigin();
    
    UFUNCTION(BlueprintCallable)
    float GetRubyHarvestRatio(FVector rubyLocation);
    
    UFUNCTION(BlueprintCallable)
    FPlayerStormEffectsInfo GetPlayerStormEffectsInfo(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    float GetLocationGlitchWallRadiusRatio(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    float GetLocationGameplayRadiusRatio(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    FVector GetClosestRubyHarvestPoint(FVector rubyLocation);
    
private:
    UFUNCTION(BlueprintCallable)
    void ClearAllLocalPointSpawnedFX();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityUpdateLocalPointSpawnedFX(float dt);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void AuthorityRemoveEffects(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void AuthorityApplyEffects(AAstroPlayerController* PlayerController);
    
};

