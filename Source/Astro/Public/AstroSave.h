#pragma once
#include "CoreMinimal.h"
#include "AstroLevelSaveChunk.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SaveGame -FallbackName=SaveGame
#include "GameFramework/SaveGame.h"
#include "AstroRemotePlayerChunk.h"
#include "CustomSerializeCallback_DEPRECATED.h"
#include "Callback_DEPRECATED.h"
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

