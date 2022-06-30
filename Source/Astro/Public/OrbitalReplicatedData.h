#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OrbitalReplicatedData.generated.h"

class USceneComponent;
class ASolarBody;

USTRUCT(BlueprintType)
struct FOrbitalReplicatedData {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FTransform SourceTransform;
    
    UPROPERTY(Export, SaveGame)
    USceneComponent* SourceComponent;
    
    UPROPERTY(SaveGame)
    FTransform SourceComponentTransform;
    
    UPROPERTY(SaveGame)
    ASolarBody* SourceOrbitingBody;
    
    UPROPERTY(SaveGame)
    FTransform TargetTransform;
    
    UPROPERTY(Export, SaveGame)
    USceneComponent* TargetComponent;
    
    UPROPERTY(SaveGame)
    FTransform TargetComponentTransform;
    
    UPROPERTY(SaveGame)
    ASolarBody* TargetOrbitingBody;
    
    UPROPERTY(SaveGame)
    FTransform CurrentTransform;
    
    UPROPERTY(Export, SaveGame)
    USceneComponent* CurrentComponent;
    
    UPROPERTY(SaveGame)
    FTransform CurrentComponentTransform;
    
    UPROPERTY(SaveGame)
    ASolarBody* CurrentOrbitingBody;
    
    UPROPERTY(SaveGame)
    bool Launched;
    
    UPROPERTY(SaveGame)
    float TravelDistance;
    
    UPROPERTY(SaveGame)
    float LaunchLength;
    
    UPROPERTY(SaveGame)
    float InterplanetaryTravelRangeMultiplier;
    
    ASTRO_API FOrbitalReplicatedData();
};

