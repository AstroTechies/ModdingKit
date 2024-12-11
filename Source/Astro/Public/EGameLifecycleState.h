#pragma once
#include "CoreMinimal.h"
#include "EGameLifecycleState.generated.h"

UENUM(BlueprintType)
enum class EGameLifecycleState : uint8 {
    Initializing,
    TerrainLoading,
    WaitingForLoadScreen,
    WaitingForSignIn,
    ReadyToStart,
    IntroCinematicTerrainLoading,
    IntroCinematic,
    TerrainFlushAndReload,
    TitleMenu,
    GameStarted,
    OutroCinematic,
    SkipIntroCinematic,
    COUNT,
};

