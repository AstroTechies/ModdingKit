#pragma once
#include "CoreMinimal.h"
#include "EAstroUIAudioEventKey.generated.h"

UENUM(BlueprintType)
enum class EAstroUIAudioEventKey : uint8 {
    Invalid,
    NoSound,
    GameMenuOpened,
    GameMenuClosed,
    GameMenuEntryGenericFocusGained,
    GameMenuEntryGenericUsed,
    GameMenuEntryGenericTabChanged,
    GameMenuPopoutPresented,
    GameMenuEntryEditStarted,
    GameMenuEntryEditCompleted,
    GameMenuEntryEditValueChanged,
    GameMenuCheckboxSetTrue,
    GameMenuCheckboxSetFalse,
    GameMenuSuitSelectionMade,
    GameMenuVisorSelectionMade,
    GameMenuPaletteSelectionMade,
    GameMenuAstropediaEntryOpened,
    GameMenuAstropediaEntryClosed,
    GameMenuQuitButtonPressed,
    GameMenuEntryGenericUsedLocked,
    CreativeColorpicker,
    CreativeTerrainToolMenuOpen,
    CreativeTerrainToolMenuClose,
    GameMenuSectionCollapsed,
    GameMenuSectionExpanded,
};

