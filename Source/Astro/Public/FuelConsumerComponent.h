#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "EFuelSource.h"
#include "SlotReference.h"
#include "FuelConsumerComponent.generated.h"

class APhysicalItem;
class USlotsComponent;
class UItemType;
class AAstroCharacter;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UFuelConsumerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    bool bOperatesOnCharacterOnly;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float LowFuelThreshold;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float FuelPerPortion;

private:
    UPROPERTY(EditDefaultsOnly)
    FName FuelSlotName;

    UPROPERTY(Transient)
    FSlotReference FuelSlotRef;

    UPROPERTY(EditDefaultsOnly)
    EFuelSource FuelSource;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemType> FuelType;

    UPROPERTY(EditDefaultsOnly)
    float ConsumptionRate;

    UPROPERTY(EditDefaultsOnly)
    float NetworkSyncFuelTimer;

    UPROPERTY(Export, Transient)
    USlotsComponent *SlotsComponent;

    UPROPERTY(Transient)
    APhysicalItem *ItemOwner;

    UPROPERTY(Transient)
    AAstroCharacter *AstroCharacter;

    UPROPERTY(Transient)
    TArray<FSlotReference> DestinationSlots;

public:
    UFuelConsumerComponent();

private:
    UFUNCTION()
    void OnItemSlotted(APhysicalItem *Item);

    UFUNCTION()
    void OnItemRemoved(APhysicalItem *Item);

    UFUNCTION()
    void OnItemAmountChanged();

public:
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetFuelType();
};
