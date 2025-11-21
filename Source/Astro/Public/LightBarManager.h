#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "AstroLightBarData.h"
#include "LightBarManager.generated.h"

class UCurveLinearColor;

UCLASS(Blueprintable)
class ULightBarManager : public UObject {
    GENERATED_BODY()
public:
    ULightBarManager();

    UFUNCTION(BlueprintCallable)
    bool UpdateColorOfLightBarRequest(const FName LightBarID, const FLinearColor LightBarColour);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateColorCurveOfLightBarRequest(const FName LightBarID, UCurveLinearColor* LightBarColorCurve);
    
    UFUNCTION(BlueprintCallable)
    bool ResetLightbarState();
    
    UFUNCTION(BlueprintCallable)
    bool RemoveLightBarRequest(const FName LightBarID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesLightBarRequestExist(const FName LightBarID);
    
    UFUNCTION(BlueprintCallable)
    bool AddLightBarColorRequestByCurve(const FName LightBarID, const uint8 LightBarPriority, UCurveLinearColor* LightBarColorCurve, const bool bIsLooping);
    
    UFUNCTION(BlueprintCallable)
    bool AddLightBarColorRequestByColor(const FName LightBarID, const uint8 LightBarPriority, const FLinearColor LightBarColour, const bool bIsLooping, const float MaxTime, const bool bIsPulsating);
    
    UFUNCTION(BlueprintCallable)
    bool AddLightBarColorRequest(const FAstroLightBarData& LightBarData);
    
};

