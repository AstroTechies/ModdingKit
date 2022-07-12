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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ERailCarMovementState movementState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DistanceFromTargetPost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentRailConnectionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LatestValidConnectionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference TargetSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bInvertRotation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentSpeedMultiplier;
    
    UPROPERTY(EditAnywhere)
    TArray<TWeakObjectPtr<APlayController>> CurrentDriver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> DesiredPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float StartingDesiredPathLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredPathLength;
    
    UPROPERTY(EditAnywhere)
    int8 RemainingPowerGracePeriodTicks;
    
    ASTRO_API FRailCarMovementReplicatedData();
};

