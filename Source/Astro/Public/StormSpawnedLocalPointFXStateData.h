#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StormSpawnedLocalPointFXStateData.generated.h"

USTRUCT(BlueprintType)
struct FStormSpawnedLocalPointFXStateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float Age;
    
    ASTRO_API FStormSpawnedLocalPointFXStateData();
};

