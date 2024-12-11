#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EFuelSource.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "FuelConsumerComponent.generated.h"

class AAstroCharacter;
class APhysicalItem;
class UItemType;
class USlotsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UFuelConsumerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOperatesOnCharacterOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LowFuelThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuelPerPortion;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FuelSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference FuelSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFuelSource FuelSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> FuelType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConsumptionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NetworkSyncFuelTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USlotsComponent* SlotsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APhysicalItem* ItemOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* AstroCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> DestinationSlots;
    
public:
    UFuelConsumerComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnItemSlotted(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemRemoved(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAmountChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetFuelType();
    
};

