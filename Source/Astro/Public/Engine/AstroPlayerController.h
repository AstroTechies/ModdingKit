// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AstroPlayerController.generated.h"

UENUM(BlueprintType)
enum class EPlayerCategory : uint8 {
	Pending = 0,
	Unlisted = 1,
	Blacklisted = 2,
	Whitelisted = 3,
	Admin = 4,
	Owner = 5
};

USTRUCT(BlueprintType)
struct ASTRO_API FPlayerInfo
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerGuid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPlayerCategory PlayerCategory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InGame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Index;
};

USTRUCT(BlueprintType)
struct ASTRO_API FPlayerList
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FPlayerInfo> PlayerInfo;
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FDSTravelInitiatedDelegate, bool, Success); // might be wrong

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FClientListPlayersResponseDelegate, FPlayerList, Players); // might be wrong

/**
 * 
 */
UCLASS(BlueprintType)
class ASTRO_API AAstroPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void TravelToDedicatedServerByURL(FString serverURL, FString password, FDSTravelInitiatedDelegate TravelInitiated);

	UFUNCTION(BlueprintCallable)
		void ServerAdminListPlayers();

	UFUNCTION(BlueprintCallable)
		void DebugTeleportCoord(FVector location);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FClientListPlayersResponseDelegate OnClientListPlayersResponse;

	UFUNCTION(BlueprintCallable)
		void AdminKickPlayer(FString playerGuid);
	UFUNCTION(BlueprintCallable, Reliable, Client)
		void ClientKickPlayerResponse(bool success);
	UFUNCTION(BlueprintCallable)
		void ForceCrash();
};
