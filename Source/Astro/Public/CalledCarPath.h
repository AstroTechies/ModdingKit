#pragma once
#include "CoreMinimal.h"
#include "CalledCarPath.generated.h"

class ARailCarBase;
class ARailPostBase;

USTRUCT(BlueprintType)
struct FCalledCarPath {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    ARailCarBase* Car;
    
    UPROPERTY(SaveGame)
    TArray<ARailPostBase*> RailPath;
    
    UPROPERTY(SaveGame)
    TArray<int32> Connections;
    
    UPROPERTY(SaveGame)
    float CarDistanceFromStation;
    
    UPROPERTY(SaveGame)
    uint8 CarFacingAway: 1;
    
    UPROPERTY(SaveGame)
    uint8 RecalledFromStationForward: 1;
    
    ASTRO_API FCalledCarPath();
};

