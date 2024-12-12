#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AstroLevelSaveChunk.h"
#include "AstroRemotePlayerChunk.h"
#include "Callback_DEPRECATED.h"
#include "CustomSerializeCallback_DEPRECATED.h"
#include "AstroSave.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroSave : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAstroLevelSaveChunk LevelChunk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroRemotePlayerChunk> RemotePlayerChunks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCustomSerializeCallback_DEPRECATED> CustomSerializeCallbacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCallback_DEPRECATED> BlueprintFixups;
    
    UAstroSave();

};

