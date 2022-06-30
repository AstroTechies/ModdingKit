#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "RailConnection.generated.h"

USTRUCT(BlueprintType)
struct FRailConnection {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    int32 ConnectionId;
    
    UPROPERTY(SaveGame)
    FSlotReference PostOneSlot;
    
    UPROPERTY(SaveGame)
    FSlotReference PostTwoSlot;
    
    UPROPERTY(SaveGame)
    uint8 bIsIndicator: 1;
    
    UPROPERTY(SaveGame)
    uint8 bIsValid: 1;
    
    UPROPERTY(SaveGame)
    uint8 bIsPostInternal: 1;
    
    ASTRO_API FRailConnection();
};

