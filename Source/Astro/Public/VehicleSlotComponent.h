#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "VehicleSlotComponent.generated.h"

class AActor;
class APhysicalItem;
class UVehicleSlotComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UVehicleSlotComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> PrinterSlots;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> TrailerSlots;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> SlotAutoConnections;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<APhysicalItem>> VehicleParts;

    UPROPERTY(EditAnywhere)
    float AutoSlotDistance;

    UPROPERTY(EditAnywhere)
    int32 MaxConnectedVehicles;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference PowerSlot;

    UVehicleSlotComponent();
    UFUNCTION(BlueprintPure)
    TArray<UVehicleSlotComponent *> GetConnectedVehicles();

    UFUNCTION(BlueprintPure)
    static UVehicleSlotComponent *ActorVehicleSlotComponent(AActor *Actor);
};
