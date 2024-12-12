#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "EPlayerPlatform.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "OnItemTypeListChangedDelegate.h"
#include "PersistedCameraState.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayerState.generated.h"

class AAstroCharacter;
class UActorEntityLinkComponent;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API AAstroPlayerState : public APlayerState {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHelpMenuStateUpdate, bool, HelpMenuViewState);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurrentResearchPointBalanceChanged OnResearchPointBalanceChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnKnownItemTypesChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnUnlockedItemTypesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHelpMenuStateUpdate OnHelpMenuUpdated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    // The PlayFab ID of a player. Seemingly only accessible on dedicated servers.
    FString BackendPlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<float> StatusModifierValues;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<float> PrevStatusModifierValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    EPlayerPlatform Platform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool HelpMenuWasViewed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FPersistedCameraState PersistedCameraState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastResearchPointBalanceChanged, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointBalance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastKnownItemTypesChanged, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> KnownItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastUnlockedItemTypesChanged, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UnlockedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bAuthorityHasAcquiredTerrainTool: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsOffworld: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsWaitingForOutro: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasPlayerExitedStartingDropship: 1;
    
public:
    AAstroPlayerState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetPlayerExitedStartingDropship();
    
    UFUNCTION(BlueprintCallable)
    void SetHelpMenuState(bool HelpMenuOpen);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItemTypes);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItemTypes);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerOffworld() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPlayerExitedStartingDropship() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPlayerPlatform GetPlayerPlatform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHelpMenuWasViewed() const;
    
    UFUNCTION(BlueprintCallable)
    void BroadcastUnlockedItemTypesChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastResearchPointBalanceChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastKnownItemTypesChanged();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityStatusModifierValuesUpdated(AAstroCharacter* Character);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityNotifyAcquiredTerrainTool();
    
};

