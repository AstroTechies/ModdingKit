#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "SlotReference.h"
#include "PowerStatics.generated.h"

class UObject;
class UPowerComponent;

UCLASS(Blueprintable)
class ASTRO_API UPowerStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPowerStatics();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetFreePower(bool Enable, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UPowerComponent*> GetSlotActorPowerComponents(FSlotReference PowerSlot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool GetFreePower(const UObject* WorldContextObject);
    
};

