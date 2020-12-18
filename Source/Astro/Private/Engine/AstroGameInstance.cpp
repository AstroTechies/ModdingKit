// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroGameInstance.h"


/*void UAstroGameInstance::DisplayLoadScreenWidget(TSubclassOf<UUserWidget> overrideWidget)
{

}*/

bool UAstroGameInstance::HasIntroCinematicCompleted()
{
	return false;
}

bool UAstroGameInstance::IsLoadingScreenActive()
{
	return false;
}

bool UAstroGameInstance::AllowLoadingScreenDismiss()
{
	return false;
}

void UAstroGameInstance::NotifyLoadScreenComplete(bool removeFromViewport)
{

}

void UAstroGameInstance::NotifyLoadScreenFadeoutComplete()
{

}

void UAstroGameInstance::NotifyPlayerExitedStartingDropship()
{

}

float UAstroGameInstance::GetEstimatedLoadPercentage(UObject* worldContextObject, const float dt, const bool lastCall)
{
	return 0;
}

void UAstroGameInstance::NotifyPlayerRespondedToWaitForInputScreen(int playerIndex)
{

}

void UAstroGameInstance::NotifyWaitForInputScreenComplete()
{

}

void UAstroGameInstance::DisplayConfirmChangeUsersPopup()
{

}

void UAstroGameInstance::NotifyPlayerConfirmedChangeUsers()
{

}

void UAstroGameInstance::NotifyPlayerCancelledChangeUsers()
{

}

void UAstroGameInstance::NotifyIntroCinematicComplete()
{

}

void UAstroGameInstance::NotifyNewGameSetupComplete()
{

}

void UAstroGameInstance::NotifyTutorialStartSelected()
{

}

void UAstroGameInstance::NotifyStartingGameDropshipSpawned()
{

}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationStarted()
{

}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationCanceled()
{

}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationCommitted()
{

}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationFinalizationStarted()
{

}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationFinalizationCanceled()
{

}

/*UAstroPlayFabTxnManager* UAstroGameInstance::GetPlayFabTxnManager()
{
	return nullptr;
}

void UAstroGameInstance::NotifyOnCharacterCustomizationPreviewRequested(FAstroCharacterCustomization customizationToPreview, bool isLocked, FTooltipWidgetDisplayData* lockedTooltipDisplayData)
{

}

void UAstroGameInstance::NotifyOnEmotePreviewRequested(UAstroEmoteDefinition* emoteDefinition, bool isLocked, FTooltipWidgetDisplayData* lockedTooltipDisplayData)
{

}*/

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationUnlockTooltipInvalidated()
{

}

bool UAstroGameInstance::IsGameInTrialMode()
{
	return false;
}

bool UAstroGameInstance::IsGameLicenseValid()
{
	return false;
}

bool UAstroGameInstance::IsPlayTogetherSessionPending()
{
	return false;
}

bool UAstroGameInstance::HasGameSessionStarted()
{
	return false;
}

void UAstroGameInstance::DebugLicenseOverride(int rawType)
{

}

void UAstroGameInstance::DebugExpirationOverride()
{

}

void UAstroGameInstance::OnInvitePasswordEntryComplete(FString password)
{

}

void UAstroGameInstance::HandleFriendsListCacheUpdated()
{

}

/*void UAstroGameInstance::HandleFriendJoinRequestFailed(EAstroFriendJoinRequestFailure JoinFailureReason)
{

}

void UAstroGameInstance::HandleFriendJoinRequestSucceeded(FFriendJoinRequestSucceededPayload joinRequestSucceededPayload)
{

}*/

void UAstroGameInstance::HandleServerListCacheUpdated()
{

}

/*FAstroPlayFabTitleData UAstroGameInstance::GetTitleData()
{

}

FAstroPlayFabMicroTxnStoreData UAstroGameInstance::GetMicroTxnStoreData()
{

}*/