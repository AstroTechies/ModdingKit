#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "OrbitalPlatformStorageCanisterComponent.generated.h"

class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UOrbitalPlatformStorageCanisterComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStoredFuelAmountChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_StoredFuel, meta=(AllowPrivateAccess=true))
    int32 REP_StoredFuel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AmountDrained;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> AcceptedItemType;
    
public:
    UOrbitalPlatformStorageCanisterComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetManagedSlots(const TArray<FSlotReference>& inSlotRefs);
    
    UFUNCTION(BlueprintCallable)
    void OnSlotEvent(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_StoredFuel() const;
    
    UFUNCTION(BlueprintCallable)
    void OnItemUnslotted(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void OnItemSlotted(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStoredFuelAmount() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityPerformJump(const int32 inFuelUsed);
    
};

