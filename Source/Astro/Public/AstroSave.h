#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AstroLevelSaveChunk.h"
#include "AstroRemotePlayerChunk.h"
#include "CustomSerializeCallback_DEPRECATED.h"
#include "Callback_DEPRECATED.h"
#include "AstroSave.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroSave : public USaveGame
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FAstroLevelSaveChunk LevelChunk;

    UPROPERTY(Transient)
    TArray<FAstroRemotePlayerChunk> RemotePlayerChunks;

    UPROPERTY(Transient)
    TArray<FCustomSerializeCallback_DEPRECATED> CustomSerializeCallbacks;

    UPROPERTY(Transient)
    TArray<FCallback_DEPRECATED> BlueprintFixups;

    UAstroSave();
};
