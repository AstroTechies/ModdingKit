#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuContext.generated.h"

UENUM(BlueprintType)
enum class EAstroGameMenuContext : uint8 {
    InGame,
    TitleMenu,
    TutorialLaunching,
    OutroCinematic,
    ExitingGame,
    DropshipSpawned,
    TitleMenuOutOfRespawnTokens,
    FMotDDisplayed,
};

