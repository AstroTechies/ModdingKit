#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "TappableObjectComponent.generated.h"

class UItemType;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTappableObjectComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> ResourceItemType;

    UPROPERTY(EditAnywhere)
    float ResourceProductionRate;

    UPROPERTY(BlueprintAssignable)
    FSignal OnTappingEfficiencyChanged;

private:
    UPROPERTY(SaveGame)
    TArray<FSlotReference> TapperSlots;

public:
    UTappableObjectComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UnregisterTapperSlot(FSlotReference tapperSlot);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterTapperSlot(FSlotReference tapperSlot);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    float GetCurrentTappingEfficiency();
};
