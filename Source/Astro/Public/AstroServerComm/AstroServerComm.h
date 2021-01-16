// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstroServerComm.generated.h"

UCLASS(BlueprintType)
class ASTRO_API UAstroServerCommExecutor : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void DSTravelFriend(FString friendName, FString password, FString index);
	UFUNCTION(BlueprintCallable)
		void DSTravelURL(FString serverURL, FString password, FString index);
	UFUNCTION(BlueprintCallable)
		void DSListGames();
	UFUNCTION(BlueprintCallable)
		void DSServerShutdown();
	UFUNCTION(BlueprintCallable)
		void DSNewGame(FString name);
	UFUNCTION(BlueprintCallable)
		void DSSaveGame(FString name);
	UFUNCTION(BlueprintCallable)
		void DSLoadGame(FString name);
	UFUNCTION(BlueprintCallable)
		void DSDeleteGame(FString name);
	UFUNCTION(BlueprintCallable)
		void DSRenameGame(FString fromName, FString toName);
	UFUNCTION(BlueprintCallable)
		void DSListPlayers();
	UFUNCTION(BlueprintCallable)
		void DSServerStatistics();
	UFUNCTION(BlueprintCallable)
		void DSGetProperties();
	UFUNCTION(BlueprintCallable)
		void DSCreativeMode(bool enable);
	UFUNCTION(BlueprintCallable)
		void DSSetFuelFreeCreative(bool enable);
	UFUNCTION(BlueprintCallable)
		void DSSetOxygenFreeCreative(bool enable);
	UFUNCTION(BlueprintCallable)
		void DSSetInvincibleCreative(bool enable);
	UFUNCTION(BlueprintCallable)
		void DSSetInvisibleToHazardsCreative(bool enable);
	UFUNCTION(BlueprintCallable)
		void DSSetBackpackPowerUnlimitedCreative(bool enable);
	UFUNCTION(BlueprintCallable)
		void DSGetServerList();
	UFUNCTION()
		void DSKickPlayerGuid(uint64 playerGuid);
	UFUNCTION(BlueprintCallable)
		void DSKickPlayer(int playerIndex);
	UFUNCTION(BlueprintCallable)
		void DSSetPassword(FString password);
	UFUNCTION(BlueprintCallable)
		void DSTravel(int serverIndex, FString password);
	UFUNCTION(BlueprintCallable)
		void DSTravelName(FString serverName, FString index, FString password);
	UFUNCTION(BlueprintCallable)
		void DSTravelPass(FString serverName, FString password, FString index);
	UFUNCTION(BlueprintCallable)
		void DSSetActivityTimeout(FString seconds);
	UFUNCTION(BlueprintCallable)
		void DSSetSaveGameInterval(FString seconds);
	UFUNCTION(BlueprintCallable)
		void DSSetDenyUnlisted(FString enable);
	UFUNCTION()
		void DSSetPlayerCategoryIdx(uint32 index, FString category);
	UFUNCTION()
		void DSSetPlayerCategoryGuid(uint64 playerGuid, FString category);
	UFUNCTION(BlueprintCallable)
		void DSSetPlayerCategory(FString player, FString category, FString index);
	UFUNCTION(BlueprintCallable)
		void DSSetPlayerCategoryForPlayerName(FString playerName, FString category);
	UFUNCTION(BlueprintCallable)
		void DSSetBackupSaveGamesInterval(FString seconds);
	UFUNCTION(BlueprintCallable)
		void DSBackupSaveGames();
	UFUNCTION(BlueprintCallable)
		void DSGetRecentsList();
	UFUNCTION(BlueprintCallable)
		void DSClearRecentsList();
	UFUNCTION(BlueprintCallable)
		void DSGetFavoritesList();
	UFUNCTION(BlueprintCallable)
		void DSAddFavorite(FString serverUrl, FString nickName);
	UFUNCTION(BlueprintCallable)
		void DSRemoveFavorite(FString serverUrl);
	UFUNCTION(BlueprintCallable)
		void DSClearFavoritesList();
	UFUNCTION(BlueprintCallable)
		void DSRemote(FString consoleCommand);
	UFUNCTION(BlueprintCallable)
		void TestProxyFailureIndex(int failIndex);
	UFUNCTION(BlueprintCallable)
		void TestProxyTimeoutIndex(int timeoutIndex);
	UFUNCTION(BlueprintCallable)
		void TestDumpProxyState();

};