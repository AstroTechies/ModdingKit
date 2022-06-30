#pragma once
#include "CoreMinimal.h"
#include "ERailCarMovementState.h"
#include "SlotReference.h"
#include "RailCarMovementReplicatedData.generated.h"

class APlayController;

USTRUCT(BlueprintType)
struct FRailCarMovementReplicatedData {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    ERailCarMovementState movementState;
    
    UPROPERTY(SaveGame)
    float DistanceFromTargetPost;
    
    UPROPERTY(SaveGame)
    int32 CurrentRailConnectionID;
    
    UPROPERTY(SaveGame)
    int32 LatestValidConnectionID;
    
    UPROPERTY()
    FSlotReference TargetSlot;
    
    UPROPERTY(SaveGame)
    uint8 bInvertRotation: 1;
    
    UPROPERTY()
    uint8 bHasPower: 1;
    
    UPROPERTY(SaveGame)
    float TargetSpeedMultiplier;
    
    UPROPERTY(SaveGame)
    float CurrentSpeedMultiplier;
    
    UPROPERTY()
    TArray<TWeakObjectPtr<APlayController>> CurrentDriver;
    
    ASTRO_API FRailCarMovementReplicatedData();
};

