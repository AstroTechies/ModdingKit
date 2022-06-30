#pragma once
#include "CoreMinimal.h"
#include "BiomeAudioEvents.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FBiomeAudioEvents {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName WeightRTPC;
    
    UPROPERTY(EditAnywhere)
    FString EnterEvent;
    
    UPROPERTY(EditAnywhere)
    FString ExitEvent;
    
    UPROPERTY(EditAnywhere)
    FString GainPrimaryEvent;
    
    UPROPERTY(EditAnywhere)
    FString LostPrimaryEvent;
    
    FBiomeAudioEvents();
};

