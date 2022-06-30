#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerState.h"
#include "EPlayerPlatform.h"
#include "OnItemTypeListChangedDelegate.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "PersistedCameraState.h"
#include "AstroPlayerState.generated.h"

class UItemType;
class UActorEntityLinkComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AAstroPlayerState : public APlayerState
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHelpMenuStateUpdate, bool, HelpMenuViewState);

    UPROPERTY()
    FOnCurrentResearchPointBalanceChanged OnResearchPointBalanceChanged;

    UPROPERTY()
    FOnItemTypeListChanged OnKnownItemTypesChanged;

    UPROPERTY()
    FOnItemTypeListChanged OnUnlockedItemTypesChanged;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FHelpMenuStateUpdate OnHelpMenuUpdated;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    FString BackendPlayerId;

private:
    UPROPERTY(Replicated, Transient)
    EPlayerPlatform Platform;

    UPROPERTY(SaveGame)
    bool HelpMenuWasViewed;

    UPROPERTY(SaveGame, Transient)
    FPersistedCameraState PersistedCameraState;

protected:
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UActorEntityLinkComponent *EntityLinkComponent;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = BroadcastResearchPointBalanceChanged, meta = (AllowPrivateAccess = true))
    float CurrentResearchPointBalance;

    UPROPERTY(BlueprintReadWrite, Replicated, Transient, meta = (AllowPrivateAccess = true))
    float CurrentResearchPointsPerMinute;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = BroadcastKnownItemTypesChanged, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> KnownItemTypes;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = BroadcastUnlockedItemTypesChanged, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> UnlockedItemTypes;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 bAuthorityHasAcquiredTerrainTool : 1;

    UPROPERTY(SaveGame)
    uint8 bIsOffworld : 1;

    UPROPERTY(Transient)
    uint8 bIsWaitingForOutro : 1;

public:
    AAstroPlayerState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetHelpMenuState(bool HelpMenuOpen);

    UFUNCTION()
    void OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>> &NewUnlockedItemTypes);

    UFUNCTION()
    void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);

    UFUNCTION()
    void OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>> &newKnownItemTypes);

    UFUNCTION(BlueprintPure)
    bool IsPlayerOffworld() const;

    UFUNCTION(BlueprintPure)
    EPlayerPlatform GetPlayerPlatform() const;

    UFUNCTION(BlueprintPure)
    bool GetHelpMenuWasViewed() const;

    UFUNCTION()
    void BroadcastUnlockedItemTypesChanged();

    UFUNCTION()
    void BroadcastResearchPointBalanceChanged();

    UFUNCTION()
    void BroadcastKnownItemTypesChanged();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityNotifyAcquiredTerrainTool();
};
