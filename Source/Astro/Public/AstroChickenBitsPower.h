#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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

