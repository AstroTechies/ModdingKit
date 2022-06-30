#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "PersistedCameraState.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FPersistedCameraState {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FVector Location;
    
    UPROPERTY(SaveGame)
    FRotator Rotation;
    
    UPROPERTY(SaveGame)
    float FOV;
    
    UPROPERTY(SaveGame)
    FTransform CameraFrameToWorld;
    
    UPROPERTY(SaveGame)
    AActor* LastNearestSolarBody;
    
    UPROPERTY(SaveGame)
    AActor* ViewTarget;
    
    ASTRO_API FPersistedCameraState();
};

