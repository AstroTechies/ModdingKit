#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameInstance -FallbackName=GameInstance
#include "OnFullLicenseActivatedDelegate.h"
#include "OnTrialLicenseActivatedDelegate.h"
#include "OnAsyncMapLoadStartedDelegate.h"
#include "OnLicenseLostDelegate.h"
#include "OnTrialExpiringSoonDelegate.h"
#include "OnLoadingScreenCompletedDelegate.h"
#include "JoinFriendSessionCompleteDelegate.h"
#include "SignalDelegate.h"
#include "AccountLinkCompleteDelegate.h"
#include "OnMultiplayerModeChangedDelegate.h"
#include "OnlineManagerErrorDelegate.h"
#include "OnGameplayStartedDelegate.h"
#include "OnJoinedAsClientDelegate.h"
#include "PlatformLogoutCompleteDelegate.h"
#include "PlatformLoginCompleteDelegate.h"
#include "ActorTemplateCache.h"
#include "WorldSingletons.h"
#include "CheckUserPrivilegeCompleteDelegate.h"
#include "MaterialInstanceCache.h"
#include "AstroGameInstance.generated.h"

class UMessageOfTheDay;
class UAstroServerCommExecutor;
class UWorld;
class UUserWidget;
class UObject;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API UAstroGameInstance : public UGameInstance
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageOfTheDayUpdated, UMessageOfTheDay *, InMessageOfTheDay);

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnTrialLicenseActivated OnTrialLicenseDetected;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnFullLicenseActivated OnFullLicenseDetected;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnLicenseLost OnLicenseLost;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnTrialExpiringSoon OnLicenseExpiringSoon;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnLoadingScreenCompleted OnLoadingScreenCompleted;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnAsyncMapLoadStarted AsyncMapLoadStarted;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnCultureChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAccountLinkComplete AccountLinkComplete;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnMultiplayerModeChanged MultiplayerModeChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnlineManagerError OnlineManagerError;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FJoinFriendSessionComplete JoinFriendSessionComplete;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnControllingUserSet;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnIntroCinematicComplete;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnNewGameSetupComplete;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnGameplayStarted OnGameplayStarted;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnTutorialStartSelected;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnStartingGameDropshipSpawned;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnSolarSystemInitialized_BlueprintEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnCachedFriendsListUpdated;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnCachedServerListUpdated;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnAllCosmeticsSeen;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnUnclaimedPhysicalItemRewardsChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnJoinedAsClient OnJoinedNetGame;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FMessageOfTheDayUpdated OnMessageOfTheDayUpdated;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal OnPlayTogetherEventReceived;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAstroServerCommExecutor *AstroServerCommSingleton;

private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FPlatformLoginComplete OnPlatformLoginCompleted;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FPlatformLogoutComplete OnPlatformLogoutCompleted;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal SessionStarted;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSignal SessionDestroed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<UWorld *, FWorldSingletons> WorldSingletons;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    UUserWidget *ActiveLoadingScreen;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    UUserWidget *ActiveWaitForInputScreen;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    UUserWidget *ActiveConfirmChangeUsersPopup;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    UUserWidget *ActiveReconnectControllerPopup;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FActorTemplateCache GlobalTemplateCache;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<UWorld *, FMaterialInstanceCache> MaterialInstanceCache;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FString LobbyId;

public:
    UAstroGameInstance();
    UFUNCTION(BlueprintCallable)
    void PlatformLogout();

    UFUNCTION(BlueprintCallable)
    void PlatformLogin();

    UFUNCTION(BlueprintCallable)
    void OnInvitePasswordEntryComplete(const FString &Password);

    UFUNCTION(BlueprintCallable)
    void NotifyWaitForInputScreenComplete();

    UFUNCTION(BlueprintCallable)
    void NotifyTutorialStartSelected();

    UFUNCTION(BlueprintCallable)
    void NotifyStartingGameDropshipSpawned();

    UFUNCTION(BlueprintCallable)
    void NotifyPlayerRespondedToWaitForInputScreen(int32 playerIndex);

    UFUNCTION(BlueprintCallable)
    void NotifyPlayerExitedStartingDropship();

    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void NotifyPlayerConfirmedChangeUsers();

    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void NotifyPlayerCancelledChangeUsers();

    UFUNCTION(BlueprintCallable)
    void NotifyOnMultiplayerModeChanged();

    UFUNCTION(BlueprintCallable)
    void NotifyNewGameSetupComplete();

    UFUNCTION(BlueprintCallable)
    void NotifyLoadScreenFadeoutComplete();

    UFUNCTION(BlueprintCallable)
    void NotifyLoadScreenComplete(bool RemoveFromViewport);

    UFUNCTION(BlueprintCallable)
    void NotifyIntroCinematicComplete();

    UFUNCTION(BlueprintCallable)
    void NotifyActorBeginPlay();

    UFUNCTION(BlueprintPure)
    bool IsPlayTogetherSessionPending() const;

    UFUNCTION(BlueprintPure)
    bool IsLoadingScreenActive();

    UFUNCTION(BlueprintCallable)
    bool IsGameLicenseValid();

    UFUNCTION(BlueprintCallable)
    bool IsGameInTrialMode();

    UFUNCTION(BlueprintPure)
    bool HasIntroCinematicCompleted();

    UFUNCTION(BlueprintPure)
    bool HasGameSessionStarted() const;

private:
    UFUNCTION()
    void HandleServerListCacheUpdated();

    UFUNCTION()
    void HandleFriendsListCacheUpdated();

public:
    UFUNCTION()
    void HandleCultureChanged();

private:
public:
    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    float GetEstimatedLoadPercentage(const UObject *WorldContextObject, const float dt, const bool lastCall);

    UFUNCTION(BlueprintCallable)
    void DisplayLoadScreenWidget(TSubclassOf<UUserWidget> overrideWidget);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void DisplayConfirmChangeUsersPopup();

    UFUNCTION(Exec)
    void DebugLicenseOverride(int32 Type);

    UFUNCTION(Exec)
    void DebugExpirationOverride();

    UFUNCTION(BlueprintCallable)
    void CheckUserPrivilege(FCheckUserPrivilegeComplete OnComplete);

    UFUNCTION(BlueprintPure)
    bool AllowLoadingScreenDismiss();
};
