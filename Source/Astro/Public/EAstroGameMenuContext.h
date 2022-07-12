#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuContext.generated.h"

UENUM()
enum class EAstroGameMenuContext : uint8 {
    InGame,
    TitleMenu,
    TutorialLaunching,
    OutroCinematic,
    ExitingGame,
    DropshipSpawned,
};

