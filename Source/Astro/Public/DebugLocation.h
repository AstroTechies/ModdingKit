#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "DebugLocation.generated.h"

USTRUCT(BlueprintType)
struct FDebugLocation {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FString Name;
    
    UPROPERTY(SaveGame)
    FVector Location;
    
    UPROPERTY(SaveGame)
    FQuat Rotation;
    
    ASTRO_API FDebugLocation();
};

