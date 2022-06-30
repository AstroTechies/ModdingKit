#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OxygenatorSignalDelegate.h"
#include "OxygenatorComponent.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UOxygenatorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOxygenatorSignal OnSupplyingOxygenChanged;

    UPROPERTY(BlueprintAssignable)
    FOxygenatorSignal OnOxygenatorEndPlay;

protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bRequiresPower : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bSuppliesOxygenToContainedCharactersOnly : 1;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = OnRep_IsSupplyingOxygen, meta = (AllowPrivateAccess = true))
    uint8 bIsSupplyingOxygen : 1;

    UPROPERTY(SaveGame)
    uint8 bIsOxygenSupplyEnabled : 1;

    UPROPERTY(Transient)
    APhysicalItem *OwnerItem;

public:
    UOxygenatorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_IsSupplyingOxygen();

    UFUNCTION()
    void OnOwnerNotFullyPowered();

    UFUNCTION()
    void OnOwnerItemRemovedFromSlot(bool bNewOwner);

    UFUNCTION()
    void OnOwnerItemPlacedInSlot();

    UFUNCTION()
    void OnOwnerFullyPowered();

    UFUNCTION()
    void OnItemPadSpawned();

    UFUNCTION()
    void OnItemPadDestroyed();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOxygenSupplyEnabled(bool bSupplyEnabled);
};
