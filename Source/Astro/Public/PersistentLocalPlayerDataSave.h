#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PersistentLocalPlayerDataSave.generated.h"

UCLASS(Blueprintable)
class UPersistentLocalPlayerDataSave : public USaveGame {
    GENERATED_BODY()
public:
    UPersistentLocalPlayerDataSave();
};

