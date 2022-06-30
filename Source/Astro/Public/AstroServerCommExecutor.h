#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroServerCommExecutor.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroServerCommExecutor : public UObject
{
    GENERATED_BODY()
public:
    UAstroServerCommExecutor();
    UFUNCTION(Exec)
    void TestProxyTimeoutIndex(int32 timeoutIndex);

    UFUNCTION(Exec)
    void TestProxyFailureIndex(int32 failIndex);

    UFUNCTION(Exec)
    void TestDumpProxyState();

    UFUNCTION(Exec)
    void DSTravelURL(const FString &ServerURL, const FString &Password, const FString &Index);

    UFUNCTION(Exec)
    void DSTravelPass(const FString &ServerName, const FString &Password, const FString &Index);

    UFUNCTION(Exec)
    void DSTravelName(const FString &ServerName, const FString &Index, const FString &Password);

    UFUNCTION(Exec)
    void DSTravelFriend(const FString &friendName, const FString &Password, const FString &Index);

    UFUNCTION(Exec)
    void DSTravel(int32 serverIndex, const FString &Password);

    UFUNCTION(Exec)
    void DSSetSaveGameInterval(const FString &Seconds);

    UFUNCTION(Exec)
    void DSSetPlayerCategoryIdx(uint32 Index, const FString &Category);

    UFUNCTION(Exec)
    void DSSetPlayerCategoryGuid(uint64 PlayerGuid, const FString &Category);

    UFUNCTION(Exec)
    void DSSetPlayerCategoryForPlayerName(const FString &PlayerName, const FString &Category);

    UFUNCTION(Exec)
    void DSSetPlayerCategory(const FString &PlayerName, const FString &Category, const FString &Index);

    UFUNCTION(Exec)
    void DSSetPassword(const FString &Password);

    UFUNCTION(Exec)
    void DSSetOxygenFreeCreative(bool Enable);

    UFUNCTION(Exec)
    void DSSetInvisibleToHazardsCreative(bool Enable);

    UFUNCTION(Exec)
    void DSSetInvincibleCreative(bool Enable);

    UFUNCTION(Exec)
    void DSSetFuelFreeCreative(bool Enable);

    UFUNCTION(Exec)
    void DSSetDenyUnlisted(const FString &Enable);

    UFUNCTION(Exec)
    void DSSetBackupSaveGamesInterval(const FString &Seconds);

    UFUNCTION(Exec)
    void DSSetBackpackPowerUnlimitedCreative(bool Enable);

    UFUNCTION(Exec)
    void DSSetActivityTimeout(const FString &Seconds);

    UFUNCTION(Exec)
    void DSServerStatistics();

    UFUNCTION(Exec)
    void DSServerShutdown();

    UFUNCTION(Exec)
    void DSSaveGame(const FString &Name);

    UFUNCTION(Exec)
    void DSRenameGame(const FString &fromName, const FString &toName);

    UFUNCTION(Exec)
    void DSRemoveFavorite(const FString &ServerName);

    UFUNCTION(Exec)
    void DSRemote(const FString &consoleCommand);

    UFUNCTION(Exec)
    void DSNewGame(const FString &Name);

    UFUNCTION(Exec)
    void DSLoadGame(const FString &Name);

    UFUNCTION(Exec)
    void DSListPlayers();

    UFUNCTION(Exec)
    void DSListGames();

    UFUNCTION(Exec)
    void DSKickPlayerGuid(uint64 PlayerGuid);

    UFUNCTION(Exec)
    void DSKickPlayer(int32 playerIndex);

    UFUNCTION(Exec)
    void DSGetServerList();

    UFUNCTION(Exec)
    void DSGetRecentsList();

    UFUNCTION(Exec)
    void DSGetProperties();

    UFUNCTION(Exec)
    void DSGetFavoritesList();

    UFUNCTION(Exec)
    void DSDeleteGame(const FString &Name);

    UFUNCTION(Exec)
    void DSCreativeMode(bool Enable);

    UFUNCTION(Exec)
    void DSClearRecentsList();

    UFUNCTION(Exec)
    void DSClearFavoritesList();

    UFUNCTION(Exec)
    void DSBackupSaveGames();

    UFUNCTION(Exec)
    void DSAddFavorite(const FString &ServerName, const FString &NickName);
};
