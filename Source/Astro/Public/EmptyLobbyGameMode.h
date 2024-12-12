#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EmptyLobbyGameMode.generated.h"

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AEmptyLobbyGameMode : public AGameModeBase {
    GENERATED_BODY()
public:
    AEmptyLobbyGameMode(const FObjectInitializer& ObjectInitializer);

};

