#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EAstroPlayerStormRadiusStates.h"
#include "PlayerStormEffectsInfo.h"
#include "PlayerStormRadiusStateChangeDelegateDelegate.h"
#include "StormSpawnedLocalPointClientComponentContainer.h"
#include "StormSpawnedLocalPointFXConfig.h"
#include "StormSpawnedLocalPointFXStateContainer.h"
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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StormID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StateIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float Lifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
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
    float WindPowerScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerGlitchWallApproachDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool LocalPointSpawnedFXEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXConfig> SpawnedFXConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_SpawnedFXStateContainers, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXStateContainer> SpawnedFXStateContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointClientComponentContainer> SpawnedLocalPointParticleSystemComponentContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXStateContainer> PrevSpawnedFXStateContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> ClientSpawnedFXActiveEmitterPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool SpawnedFXStateContainersInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerEnteredStorm;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerExitedStorm;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerEnteredEye;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStormRadiusStateChangeDelegate PlayerExitedEye;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
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
    UParticleSystemComponent* SpawnLocalPointSpawnedFX(UParticleSystem* ParticleTemplate, FVector Position, FTransform SpawnTransform, float NewAge);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetPlayerStormRadiusState(AAstroPlayerController* PlayerController, EAstroPlayerStormRadiusStates State);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayerExitedStorm(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayerEnteredStorm(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    void RegisterPlayerForStormEffectsTracking(AAstroPlayerController* PlayerController);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnVirusProtectionUpdated();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRep_SpawnedFXStateContainers();
    
private:
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

