#pragma once
#include "CoreMinimal.h"
//#include "EAstroFriendJoinRequestFailure.h"
//#include "FriendJoinRequestSucceededPayload.h"
//#include "AstroPlayFabMicroTxnStoreData.h"
//#include "AstroPlayFabTitleData.h"
//#include "AstroServerInfo.h"
#include "Engine/GameInstance.h"
#include "AccountLinkCompleteDelegate.h"
#include "ActorTemplateCache.h"
#include "AstroCharacterCustomization.h"
#include "CheckUserPrivilegeCompleteDelegate.h"
#include "JoinFriendSessionCompleteDelegate.h"
#include "MaterialInstanceCache.h"
#include "NetworkStatusMightHaveChangedDelegate.h"
#include "OnAsyncMapLoadStartedDelegate.h"
#include "OnCharacterCustomizationPreviewRequestedDelegate.h"
#include "OnEmotePreviewRequestedDelegate.h"
#include "OnFullLicenseActivatedDelegate.h"
#include "OnGameplayStartedDelegate.h"
#include "OnJoinedAsClientDelegate.h"
#include "OnLicenseLostDelegate.h"
#include "OnLoadingScreenCompletedDelegate.h"
#include "OnMultiplayerModeChangedDelegate.h"
#include "OnTrialExpiringSoonDelegate.h"
#include "OnTrialLicenseActivatedDelegate.h"
#include "OnlineManagerErrorDelegate.h"
#include "PlatformLoginCompleteDelegate.h"
#include "PlatformLogoutCompleteDelegate.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "TooltipWidgetDisplayData.h"
#include "WorldSingletons.h"
#include "AstroGameInstance.generated.h"

//class UAstroDlcManager;
class UAstroEmoteDefinition;
//class UAstroPlayFabTxnManager;
class UAstroServerCommExecutor;
class UMessageOfTheDay;
class UObject;
class UUserWidget;
class UWorld;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API UAstroGameInstance : public UGameInstance {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageOfTheDayUpdated, UMessageOfTheDay*, InMessageOfTheDay);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHideFullscreenMessageOfTheDay);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDisplayFullscreenMessageOfTheDay);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNetworkStatusMightHaveChanged OnNetworkStatusMightHaveChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTrialLicenseActivated OnTrialLicenseDetected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFullLicenseActivated OnFullLicenseDetected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLicenseLost OnLicenseLost;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTrialExpiringSoon OnLicenseExpiringSoon;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLoadingScreenCompleted OnLoadingScreenCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAsyncMapLoadStarted AsyncMapLoadStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCultureChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAccountLinkComplete AccountLinkComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMultiplayerModeChanged MultiplayerModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnlineManagerError OnlineManagerError;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FJoinFriendSessionComplete JoinFriendSessionComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnControllingUserSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnIntroCinematicComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnNewGameSetupComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameplayStarted OnGameplayStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTutorialStartSelected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStartingGameDropshipSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSolarSystemInitialized_BlueprintEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCachedFriendsListUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCachedServerListUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAllCosmeticsSeen;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnUnclaimedPhysicalItemRewardsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayFabTitleDataRefreshed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayFabMicroTxnStoreDataRefreshed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnTitleScreenCharacterCustomizationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnTitleScreenCharacterCustomizationCanceled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnTitleScreenCharacterCustomizationCommitted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnTitleScreenCharacterCustomizationUnlockTooltipInvalidated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnTitleScreenCharacterCustomizationFinalizationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnTitleScreenCharacterCustomizationFinalizationCanceled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnCharacterCustomizationPreviewRequested OnCharacterCustomizationPreviewRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnEmotePreviewRequested OnEmotePreviewRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnJoinedAsClient OnJoinedNetGame;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMessageOfTheDayUpdated OnMessageOfTheDayUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDisplayFullscreenMessageOfTheDay OnDisplayFullscreenMessageOfTheDay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHideFullscreenMessageOfTheDay OnHideFullscreenMessageOfTheDay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayTogetherEventReceived;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroServerCommExecutor* AstroServerCommSingleton;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    FAstroServerInfo InviteServerInfo;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlatformLoginComplete OnPlatformLoginCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlatformLogoutComplete OnPlatformLogoutCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal SessionStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal SessionDestroed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool SanitizeNonPersistentPlacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool SanitizeInactiveLTEPlacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool SanitizeCompletedMissionPlacements;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoadingMenuAfterKickedFromSession;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FWorldSingletons> WorldSingletons;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    UAstroPlayFabTxnManager* PlayFabTxnManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* ActiveLoadingScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* ActiveWaitForInputScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* ActiveConfirmChangeUsersPopup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* ActiveReconnectControllerPopup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FActorTemplateCache GlobalTemplateCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FMaterialInstanceCache> MaterialInstanceCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString LobbyId;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    UAstroDlcManager* DlcManager;
    
public:
    UAstroGameInstance();

    UFUNCTION(BlueprintCallable)
    void SetSanitizeNonPersistentPlacements(bool Sanitize);
    
    UFUNCTION(BlueprintCallable)
    void SetSanitizeInactiveLTEPlacements(bool Sanitize);
    
    UFUNCTION(BlueprintCallable)
    void SetSanitizeCompletedMissionPlacements(bool Sanitize);
    
    UFUNCTION(BlueprintCallable)
    void SetIsTransitioningToExpansionViaPortal(bool viaPortal);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveSaveFileDescriptiveName(const FString& newName);
    
    UFUNCTION(BlueprintCallable)
    void PlatformLogout();
    
    UFUNCTION(BlueprintCallable)
    void PlatformLogin();
    
    UFUNCTION(BlueprintCallable)
    void OnInvitePasswordEntryComplete(const FString& Password);
    
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
    void NotifyOnEmotePreviewRequested(UAstroEmoteDefinition* emoteDefinition, bool IsLocked, FTooltipWidgetDisplayData lockedTooltipDisplayData);
    
    UFUNCTION(BlueprintCallable)
    void NotifyOnCharacterCustomizationPreviewRequested(const FAstroCharacterCustomization& customizationToPreview, bool IsLocked, FTooltipWidgetDisplayData lockedTooltipDisplayData);
    
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
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayTogetherSessionPending() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoadingScreenActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsGameLicenseValid();
    
    UFUNCTION(BlueprintCallable)
    bool IsGameInTrialMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMicroTxnStoreDataUpdated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasIntroCinematicCompleted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasGameSessionStarted() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleServerListCacheUpdated();
    
    UFUNCTION(BlueprintCallable)
    void HandleFriendsListCacheUpdated();
    
//    UFUNCTION(BlueprintCallable)
//    void HandleFriendJoinRequestSucceeded(const FFriendJoinRequestSucceededPayload& joinRequestSucceededPayload);
    
//    UFUNCTION(BlueprintCallable)
//    void HandleFriendJoinRequestFailed(EAstroFriendJoinRequestFailure JoinFailureReason);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleCultureChanged();
    
private:
//    UFUNCTION(BlueprintCallable, BlueprintPure)
//    FAstroPlayFabTitleData GetTitleData();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSanitizeNonPersistentPlacements() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSanitizeInactiveLTEPlacements() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSanitizeCompletedMissionPlacements() const;
    
//    UFUNCTION(BlueprintCallable, BlueprintPure)
//    UAstroPlayFabTxnManager* GetPlayFabTxnManager();
    
private:
//    UFUNCTION(BlueprintCallable, BlueprintPure)
//    FAstroPlayFabMicroTxnStoreData GetMicroTxnStoreData();
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetIsTransitioningToExpansionViaPortal();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    float GetEstimatedLoadPercentage(const UObject* WorldContextObject, const float dt, const bool lastCall);
    
//    UFUNCTION(BlueprintCallable, BlueprintPure)
//    UAstroDlcManager* GetDlcManager();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetActiveSaveFileDescriptiveName() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceRefreshMicroTxnStoreData();
    
    UFUNCTION(BlueprintCallable)
    void DisplayLoadScreenWidget(TSubclassOf<UUserWidget> overrideWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void DisplayConfirmChangeUsersPopup();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugLicenseOverride(int32 Type);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugExpirationOverride();
    
    UFUNCTION(BlueprintCallable)
    void CheckUserPrivilege(FCheckUserPrivilegeComplete OnComplete);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowLoadingScreenDismiss();
    
};

