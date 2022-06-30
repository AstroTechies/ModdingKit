#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SlotReference.h"
#include "PowerStatics.generated.h"

class UPowerComponent;
class UObject;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UPowerStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UPowerStatics();
    UFUNCTION(BlueprintCallable)
    static void SetFreePower(bool Enable, UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static TArray<UPowerComponent *> GetSlotActorPowerComponents(FSlotReference PowerSlot);

    UFUNCTION(BlueprintPure)
    static bool GetFreePower(const UObject *WorldContextObject);
};
