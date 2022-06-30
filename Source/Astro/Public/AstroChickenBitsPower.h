#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroChickenBitsPower.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAstroChickenBitsPower : public UObject
{
    GENERATED_BODY()
public:
    UAstroChickenBitsPower();
    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Power_VisualizeWindPowerGenerators();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Power_UseStreamingPowerDebugVisualization();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Power_UseStreamingPower();
};
