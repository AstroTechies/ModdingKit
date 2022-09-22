#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "ViewDataChangedDelegate.h"
#include "EnableSignalDelegate.h"
#include "ItemCondensedSignalDelegate.h"
#include "AtmosphericCondenserReplicationData.h"
#include "EAtmosphericCondenserState.h"
#include "SlotReference.h"
#include "AtmosphericCondenserBase.generated.h"

class UItemType;
class UPowerComponent;
class AAstroPlanet;
class UDynamicWhitelistOrganizationRule;

UCLASS(Abstract, Blueprintable)
class AAtmosphericCondenserBase : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FViewDataChanged OnViewDataChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnLoopProductionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemCondensedSignal AuthorityOnItemCondensed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicationDataChanged, meta=(AllowPrivateAccess=true))
    FAtmosphericCondenserReplicationData ReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAtmosphericCondenserReplicationData PrevReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OutputSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseProductionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_LoopProduction, meta=(AllowPrivateAccess=true))
    uint8 bLoopProduction: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EAtmosphericCondenserState CondenserState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> CurrentAtmosphericResourceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentHarvestedAtmosphereAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroPlanet* CurrentPlanet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference OutputSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> OutputSlotArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicWhitelistOrganizationRule* OutputOrganizationRule;
    
public:
    AAtmosphericCondenserBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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

