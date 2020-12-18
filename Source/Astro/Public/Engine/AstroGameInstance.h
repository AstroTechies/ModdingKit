// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Utilities/ActivationSignals.h"
#include "AstroGameInstance.generated.h"

UCLASS(BlueprintType)
class ASTRO_API UAstroGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/*UFUNCTION(BlueprintCallable)
		void DisplayLoadScreenWidget(TSubclassOf<UUserWidget> overrideWidget);*/
	UFUNCTION(BlueprintCallable)
		bool HasIntroCinematicCompleted();
	UFUNCTION(BlueprintCallable)
		bool IsLoadingScreenActive();
	UFUNCTION(BlueprintCallable)
		bool AllowLoadingScreenDismiss();
	UFUNCTION(BlueprintCallable)
		void NotifyLoadScreenComplete(bool removeFromViewport);
	UFUNCTION(BlueprintCallable)
		void NotifyLoadScreenFadeoutComplete();
	UFUNCTION(BlueprintCallable)
		void NotifyPlayerExitedStartingDropship();
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "worldContextObject"))
		float GetEstimatedLoadPercentage(UObject* worldContextObject, const float dt, const bool lastCall);
	UFUNCTION(BlueprintCallable)
		void NotifyPlayerRespondedToWaitForInputScreen(int playerIndex);
	UFUNCTION(BlueprintCallable)
		void NotifyWaitForInputScreenComplete();
	UFUNCTION(BlueprintCallable)
		void DisplayConfirmChangeUsersPopup();
	UFUNCTION(BlueprintCallable)
		void NotifyPlayerConfirmedChangeUsers();
	UFUNCTION(BlueprintCallable)
		void NotifyPlayerCancelledChangeUsers();
	UFUNCTION(BlueprintCallable)
		void NotifyIntroCinematicComplete();
	UFUNCTION(BlueprintCallable)
		void NotifyNewGameSetupComplete();
	UFUNCTION(BlueprintCallable)
		void NotifyTutorialStartSelected();
	UFUNCTION(BlueprintCallable)
		void NotifyStartingGameDropshipSpawned();
	UFUNCTION(BlueprintCallable)
		void NotifyOnTitleScreenCharacterCustomizationStarted();
	UFUNCTION(BlueprintCallable)
		void NotifyOnTitleScreenCharacterCustomizationCanceled();
	UFUNCTION(BlueprintCallable)
		void NotifyOnTitleScreenCharacterCustomizationCommitted();
	UFUNCTION(BlueprintCallable)
		void NotifyOnTitleScreenCharacterCustomizationFinalizationStarted();
	UFUNCTION(BlueprintCallable)
		void NotifyOnTitleScreenCharacterCustomizationFinalizationCanceled();
	/*UFUNCTION(BlueprintCallable)
		UAstroPlayFabTxnManager* GetPlayFabTxnManager();
	UFUNCTION(BlueprintCallable)
		void NotifyOnCharacterCustomizationPreviewRequested(FAstroCharacterCustomization customizationToPreview, bool isLocked, FTooltipWidgetDisplayData* lockedTooltipDisplayData);
	UFUNCTION(BlueprintCallable)
		void NotifyOnEmotePreviewRequested(UAstroEmoteDefinition* emoteDefinition, bool isLocked, FTooltipWidgetDisplayData* lockedTooltipDisplayData);*/
	UFUNCTION(BlueprintCallable)
		void NotifyOnTitleScreenCharacterCustomizationUnlockTooltipInvalidated();
	UFUNCTION(BlueprintCallable)
		bool IsGameInTrialMode();
	UFUNCTION(BlueprintCallable)
		bool IsGameLicenseValid();
	UFUNCTION(BlueprintCallable)
		bool IsPlayTogetherSessionPending();
	UFUNCTION(BlueprintCallable)
		bool HasGameSessionStarted();
	UFUNCTION(BlueprintCallable)
		void DebugLicenseOverride(int rawType);
	UFUNCTION(BlueprintCallable)
		void DebugExpirationOverride();
	UFUNCTION(BlueprintCallable)
		void OnInvitePasswordEntryComplete(FString password);
	UFUNCTION(BlueprintCallable)
		void HandleFriendsListCacheUpdated();
	/*UFUNCTION(BlueprintCallable)
		void HandleFriendJoinRequestFailed(EAstroFriendJoinRequestFailure JoinFailureReason);
	UFUNCTION(BlueprintCallable)
		void HandleFriendJoinRequestSucceeded(FFriendJoinRequestSucceededPayload joinRequestSucceededPayload);*/
	UFUNCTION(BlueprintCallable)
		void HandleServerListCacheUpdated();
	/*UFUNCTION(BlueprintCallable)
		FAstroPlayFabTitleData GetTitleData();
	UFUNCTION(BlueprintCallable)
		FAstroPlayFabMicroTxnStoreData GetMicroTxnStoreData();*/

	/*UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnTrialLicenseActivated OnTrialLicenseDetected;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnFullLicenseActivated OnFullLicenseDetected;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnLicenseLost OnLicenseLost;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnTrialExpiringSoon OnLicenseExpiringSoon;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnLoadingScreenCompleted OnLoadingScreenCompleted;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnAsyncMapLoadStarted AsyncMapLoadStarted;*/
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnControllingUserSet;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnIntroCinematicComplete;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnNewGameSetupComplete;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnGameplayStarted OnGameplayStarted;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTutorialStartSelected;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnStartingGameDropshipSpawned;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnSolarSystemInitialized_BlueprintEvent;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnCachedFriendsListUpdated;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnCachedServerListUpdated;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnAllCosmeticsSeen;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnUnclaimedPhysicalItemRewardsChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnPlayFabTitleDataRefreshed;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnPlayFabMicroTxnStoreDataRefreshed;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTitleScreenCharacterCustomizationStarted;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTitleScreenCharacterCustomizationCanceled;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTitleScreenCharacterCustomizationCommitted;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTitleScreenCharacterCustomizationUnlockTooltipInvalidated;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTitleScreenCharacterCustomizationFinalizationStarted;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnTitleScreenCharacterCustomizationFinalizationCanceled;
	/*UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnCharacterCustomizationPreviewRequested OnCharacterCustomizationPreviewRequested;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnEmotePreviewRequested OnEmotePreviewRequested;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnJoinedAsClient OnJoinedNetGame;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		UAstroGameInstance::FMessageOfTheDayUpdated OnMessageOfTheDayUpdated;*/
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnPlayTogetherEventReceived;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroServerCommExecutor* AstroServerCommSingleton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAstroServerInfo InviteServerInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<UWorld *,FWorldSingletons> WorldSingletons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroPlayFabTxnManager* PlayFabTxnManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* ActiveLoadingScreen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* ActiveWaitForInputScreen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* ActiveConfirmChangeUsersPopup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* ActiveReconnectControllerPopup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FActorTemplateCache GlobalTemplateCache;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<UWorld *,FMaterialInstanceCache>> MaterialInstanceCache;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString LobbyId;
};