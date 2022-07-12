#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameModeBase -FallbackName=GameModeBase
#include "EmptyLobbyGameMode.generated.h"

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AEmptyLobbyGameMode : public AGameModeBase {
    GENERATED_BODY()
public:
    AEmptyLobbyGameMode();
};

