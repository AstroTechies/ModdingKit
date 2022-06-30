#pragma once
#include "CoreMinimal.h"
#include "RailPath.generated.h"

class ARailPostBase;

USTRUCT()
struct FRailPath {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FName EntryCarSlot;
    
    UPROPERTY(SaveGame)
    ARailPostBase* StartPost;
    
    UPROPERTY(SaveGame)
    TArray<ARailPostBase*> RailPath;
    
    UPROPERTY(SaveGame)
    TArray<int32> Connections;
    
    UPROPERTY(SaveGame)
    float TotalPathDistance;
    
    UPROPERTY(SaveGame)
    uint8 RecalledFromStationForward: 1;
    
    ASTRO_API FRailPath();
};

