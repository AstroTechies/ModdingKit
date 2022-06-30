#pragma once
#include "CoreMinimal.h"
#include "EStationMarkerType.h"
#include "MarkerStationList.generated.h"

class ARailPostStation;

USTRUCT(BlueprintType)
struct FMarkerStationList {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TMap<EStationMarkerType, ARailPostStation*> StationsByMarker;
    
    UPROPERTY(SaveGame)
    TMap<ARailPostStation*, EStationMarkerType> MarkersByStation;
    
    ASTRO_API FMarkerStationList();
};

