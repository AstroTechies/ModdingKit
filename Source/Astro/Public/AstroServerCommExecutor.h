#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroServerCommExecutor.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroServerCommExecutor : public UObject {
    GENERATED_BODY()
public:
    UAstroServerCommExecutor();

    UFUNCTION(BlueprintCallable, Exec)
    void TestProxyTimeoutIndex(int32 timeoutIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestProxyFailureIndex(int32 failIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestDumpProxyState();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSTravelURL(const FString& ServerURL, const FString& Password, const FString& Index);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSTravelPass(const FString& ServerName, const FString& Password, const FString& Index);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSTravelName(const FString& ServerName, const FString& Index, const FString& Password);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSTravelFriend(const FString& friendName, const FString& Password, const FString& Index);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSTravel(int32 serverIndex, const FString& Password);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetSaveGameInterval(const FString& Seconds);
    
    UFUNCTION(Exec)
    void DSSetPlayerCategoryIdx(uint32 Index, const FString& Category);
    
    UFUNCTION(Exec)
    void DSSetPlayerCategoryGuid(uint64 PlayerGuid, const FString& Category);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetPlayerCategoryForPlayerName(const FString& PlayerName, const FString& Category);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetPlayerCategory(const FString& PlayerName, const FString& Category, const FString& Index);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetPassword(const FString& Password);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetOxygenFreeCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetInvisibleToHazardsCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetInvincibleCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetFuelFreeCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetDenyUnlisted(const FString& Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetBackupSaveGamesInterval(const FString& Seconds);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetBackpackPowerUnlimitedCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSetActivityTimeout(const FString& Seconds);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSServerStatistics();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSServerShutdown();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSSaveGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSRenameGame(const FString& fromName, const FString& toName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSRemoveFavorite(const FString& ServerName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSRemote(const FString& consoleCommand);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSNewGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSLoadGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSListPlayers();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSListGames();
    
    UFUNCTION(Exec)
    void DSKickPlayerGuid(uint64 PlayerGuid);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSKickPlayer(int32 playerIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSGetServerList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSGetRecentsList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSGetProperties();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSGetFavoritesList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSDeleteGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSCreativeMode(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSClearRecentsList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSClearFavoritesList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSBackupSaveGames();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DSAddFavorite(const FString& ServerName, const FString& NickName);
    
};

