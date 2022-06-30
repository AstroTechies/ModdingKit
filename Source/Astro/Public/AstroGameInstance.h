#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnLoadingScreenCompletedDelegate.h"
#include "OnTrialExpiringSoonDelegate.h"
#include "Engine/GameInstance.h"
#include "OnFullLicenseActivatedDelegate.h"
#include "OnTrialLicenseActivatedDelegate.h"
#include "OnLicenseLostDelegate.h"
#include "OnAsyncMapLoadStartedDelegate.h"
#include "TooltipWidgetDisplayData.h"
#include "SignalDelegate.h"
#include "AccountLinkCompleteDelegate.h"
#include "OnMultiplayerModeChangedDelegate.h"
#include "WorldSingletons.h"
#include "OnlineManagerErrorDelegate.h"
#include "JoinFriendSessionCompleteDelegate.h"
#include "OnGameplayStartedDelegate.h"
#include "OnJoinedAsClientDelegate.h"
#include "PlatformLoginCompleteDelegate.h"
#include "PlatformLogoutCompleteDelegate.h"
#include "ActorTemplateCache.h"
#include "MaterialInstanceCache.h"
#include "CheckUserPrivilegeCompleteDelegate.h"
#include "AstroGameInstance.generated.h"

class UObject;
class UUserWidget;
class UMessageOfTheDay;
class UWorld;
class UAstroServerCommExecutor;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API UAstroGameInstance : public UGameInstance
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageOfTheDayUpdated, UMessageOfTheDay *, InMessageOfTheDay);

    UPROPERTY(BlueprintAssignable)
    FOnTrialLicenseActivated OnTrialLicenseDetected;

    UPROPERTY(BlueprintAssignable)
    FOnFullLicenseActivated OnFullLicenseDetected;

    UPROPERTY(BlueprintAssignable)
    FOnLicenseLost OnLicenseLost;

    UPROPERTY(BlueprintAssignable)
    FOnTrialExpiringSoon OnLicenseExpiringSoon;

    UPROPERTY(BlueprintAssignable)
    FOnLoadingScreenCompleted OnLoadingScreenCompleted;

    UPROPERTY(BlueprintAssignable)
    FOnAsyncMapLoadStarted AsyncMapLoadStarted;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCultureChanged;

    UPROPERTY(BlueprintAssignable)
    FAccountLinkComplete AccountLinkComplete;

    UPROPERTY(BlueprintAssignable)
    FOnMultiplayerModeChanged MultiplayerModeChanged;

    UPROPERTY(BlueprintAssignable)
    FOnlineManagerError OnlineManagerError;

    UPROPERTY(BlueprintAssignable)
    FJoinFriendSessionComplete JoinFriendSessionComplete;

    UPROPERTY(BlueprintAssignable)
    FSignal OnControllingUserSet;

    UPROPERTY(BlueprintAssignable)
    FSignal OnIntroCinematicComplete;

    UPROPERTY(BlueprintAssignable)
    FSignal OnNewGameSetupComplete;

    UPROPERTY(BlueprintAssignable)
    FOnGameplayStarted OnGameplayStarted;

    UPROPERTY(BlueprintAssignable)
    FSignal OnTutorialStartSelected;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStartingGameDropshipSpawned;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSolarSystemInitialized_BlueprintEvent;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCachedFriendsListUpdated;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCachedServerListUpdated;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAllCosmeticsSeen;

    UPROPERTY(BlueprintAssignable)
    FSignal OnUnclaimedPhysicalItemRewardsChanged;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnTitleScreenCharacterCustomizationStarted;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnTitleScreenCharacterCustomizationCanceled;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnTitleScreenCharacterCustomizationCommitted;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnTitleScreenCharacterCustomizationUnlockTooltipInvalidated;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnTitleScreenCharacterCustomizationFinalizationStarted;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnTitleScreenCharacterCustomizationFinalizationCanceled;

    UPROPERTY(BlueprintAssignable)
    FOnJoinedAsClient OnJoinedNetGame;

    UPROPERTY(BlueprintAssignable)
    FMessageOfTheDayUpdated OnMessageOfTheDayUpdated;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlayTogetherEventReceived;

    UPROPERTY()
    UAstroServerCommExecutor *AstroServerCommSingleton;

private:
    UPROPERTY(BlueprintAssignable)
    FPlatformLoginComplete OnPlatformLoginCompleted;

    UPROPERTY(BlueprintAssignable)
    FPlatformLogoutComplete OnPlatformLogoutCompleted;

    UPROPERTY(BlueprintAssignable)
    FSignal SessionStarted;

    UPROPERTY(BlueprintAssignable)
    FSignal SessionDestroed;

    UPROPERTY()
    TMap<UWorld *, FWorldSingletons> WorldSingletons;

    UPROPERTY(Export)
    UUserWidget *ActiveLoadingScreen;

    UPROPERTY(Export)
    UUserWidget *ActiveWaitForInputScreen;

    UPROPERTY(Export)
    UUserWidget *ActiveConfirmChangeUsersPopup;

    UPROPERTY(Export)
    UUserWidget *ActiveReconnectControllerPopup;

    UPROPERTY(Transient)
    FActorTemplateCache GlobalTemplateCache;

    UPROPERTY(Transient)
    TMap<UWorld *, FMaterialInstanceCache> MaterialInstanceCache;

    UPROPERTY(Transient)
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
    void NotifyOnTitleScreenCharacterCustomizationUnlockTooltipInvalidated();

    UFUNCTION(BlueprintCallable)
    void NotifyOnTitleScreenCharacterCustomizationStarted();

    UFUNCTION(BlueprintCallable)
    void NotifyOnTitleScreenCharacterCustomizationFinalizationStarted();

    UFUNCTION(BlueprintCallable)
    void NotifyOnTitleScreenCharacterCustomizationFinalizationCanceled();

    UFUNCTION(BlueprintCallable)
    void NotifyOnTitleScreenCharacterCustomizationCommitted();

    UFUNCTION(BlueprintCallable)
    void NotifyOnTitleScreenCharacterCustomizationCanceled();

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

public:
    UFUNCTION()
    void HandleCultureChanged();

public:
    UFUNCTION(BlueprintPure)
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
