#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "PlayerProperties.h"
#include "AstroServerSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config = Game)
class UAstroServerSettings : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere)
    float MaxServerFramerate;

    UPROPERTY(Config, EditAnywhere)
    float MaxServerIdleFramerate;

    UPROPERTY(Config, EditAnywhere)
    uint32 MaximumPlayerCount;

    UPROPERTY(Config, EditAnywhere)
    bool bLoadAutoSave;

    UPROPERTY(Config, EditAnywhere)
    FString ExitSemaphore;

    UPROPERTY(Config, EditAnywhere)
    bool bWaitForPlayersBeforeShutdown;

    UPROPERTY(Config, EditAnywhere)
    int32 ConsolePort;

    UPROPERTY(Config, EditAnywhere)
    FString ConsolePassword;

    UPROPERTY(Config, EditAnywhere)
    FString PublicIP;

    UPROPERTY(Config, EditAnywhere)
    int32 HeartbeatInterval;

    UPROPERTY(Config, EditAnywhere)
    FString ServerName;

    UPROPERTY(Config)
    FGuid ServerGuid;

    UPROPERTY(Config, EditAnywhere)
    FString OwnerName;

    UPROPERTY(Config, EditAnywhere)
    uint64 OwnerGuid;

    UPROPERTY(Config, EditAnywhere)
    int32 PlayerActivityTimeout;

    UPROPERTY(Config, EditAnywhere)
    FString ServerPassword;

    UPROPERTY(Config, EditAnywhere)
    bool bDisableServerTravel;

    UPROPERTY(Config, EditAnywhere)
    TArray<FPlayerProperties> PlayerProperties;

    UPROPERTY(Config, EditAnywhere)
    bool DenyUnlistedPlayers;

    UPROPERTY(Config, EditAnywhere)
    bool VerbosePlayerProperties;

    UPROPERTY(Transient)
    bool Dirty;

    UPROPERTY(Config, EditAnywhere)
    int32 AutoSaveGameInterval;

    UPROPERTY(Config, EditAnywhere)
    int32 BackupSaveGamesInterval;

    UPROPERTY(Config, EditAnywhere)
    FString ActiveSaveFileDescriptiveName;

private:
    UPROPERTY(Config)
    FString ServerAdvertisedName;

public:
    UAstroServerSettings();
};
