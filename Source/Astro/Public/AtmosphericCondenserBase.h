#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotReference.h"
#include "EnableSignalDelegate.h"
#include "PhysicalItem.h"
#include "ViewDataChangedDelegate.h"
#include "ItemCondensedSignalDelegate.h"
#include "AtmosphericCondenserReplicationData.h"
#include "EAtmosphericCondenserState.h"
#include "AtmosphericCondenserBase.generated.h"

class AAstroPlanet;
class UItemType;
class UPowerComponent;

UCLASS(Blueprintable, Abstract)
class AAtmosphericCondenserBase : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FViewDataChanged OnViewDataChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnLoopProductionChanged;

    UPROPERTY(BlueprintAssignable)
    FItemCondensedSignal AuthorityOnItemCondensed;

protected:
    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnReplicationDataChanged, meta = (AllowPrivateAccess = true))
    FAtmosphericCondenserReplicationData ReplicationData;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FAtmosphericCondenserReplicationData PrevReplicationData;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FName OutputSlotName;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float BaseProductionRate;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_LoopProduction, meta = (AllowPrivateAccess = true))
    uint8 bLoopProduction : 1;

private:
    UPROPERTY(SaveGame)
    EAtmosphericCondenserState CondenserState;

    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> CurrentAtmosphericResourceType;

    UPROPERTY(SaveGame)
    float CurrentHarvestedAtmosphereAmount;

    UPROPERTY(Transient)
    AAstroPlanet *CurrentPlanet;

    UPROPERTY(Transient)
    FSlotReference OutputSlotRef;

    UPROPERTY()
    TArray<FSlotReference> OutputSlotArray;

    UPROPERTY(Export)
    UPowerComponent *PowerComponent;

public:
    AAtmosphericCondenserBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnReplicationDataChanged();

    UFUNCTION()
    void OnRep_LoopProduction();

public:
    UFUNCTION(BlueprintPure)
    float GetEffectiveProductionDuration() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOuputResourceIndex(int32 NewSelectedOutputResourceIndex);

private:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLoopProductionEnabled(bool LoopProductionIsEnabled);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityIncrementOuputResourceIndex();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityDecrementOuputResourceIndex();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityAttemptToToggleProduction();
};
