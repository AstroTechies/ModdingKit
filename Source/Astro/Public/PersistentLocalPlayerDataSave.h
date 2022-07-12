#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SaveGame -FallbackName=SaveGame
#include "GameFramework/SaveGame.h"
#include "PersistentLocalPlayerDataSave.generated.h"

UCLASS(Blueprintable)
class UPersistentLocalPlayerDataSave : public USaveGame {
    GENERATED_BODY()
public:
    UPersistentLocalPlayerDataSave();
};

