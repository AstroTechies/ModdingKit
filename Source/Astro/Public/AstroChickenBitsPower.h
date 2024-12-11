#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroChickenBitsPower.generated.h"

UCLASS(Blueprintable)
class UAstroChickenBitsPower : public UObject {
    GENERATED_BODY()
public:
    UAstroChickenBitsPower();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Power_VisualizeWindPowerGenerators();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Power_UseStreamingPowerDebugVisualization();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Power_UseStreamingPower();
    
};

