#pragma once
#include "CoreMinimal.h"
#include "EnableSignalDelegate.h"
#include "IndicatorInfo.h"
#include "PrinterComponent.h"
#include "ReplicatedMegastructurePrinterState.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "MegastructurePrinterLogicComponent.generated.h"

class AActor;
class AMegaStructure;
class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UMegastructurePrinterLogicComponent : public UPrinterComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnMegastructureProductionModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMegastructurePrinterStateUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFailedToStartPrint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPrintedFinalTier;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MegastructureItemType, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> REP_MegastructureItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MegastructurePrinterStateAtomic, meta=(AllowPrivateAccess=true))
    FReplicatedMegastructurePrinterState REP_MegastructurePrinterState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_PrintedMegastructure, meta=(AllowPrivateAccess=true))
    AMegaStructure* REP_PrintedMegastructure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_IsInMegastructureProductionMode, meta=(AllowPrivateAccess=true))
    uint8 REP_bIsMegastructureProductionModeEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemType* MegastructureItemTypeCDO;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIndicatorInfo> Indicators;
    
public:
    UMegastructurePrinterLogicComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnSlotEvent(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PrintedMegastructure();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MegastructurePrinterStateAtomic(FReplicatedMegastructurePrinterState prevState);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MegastructureItemType();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsInMegastructureProductionMode();
    
    UFUNCTION(BlueprintCallable)
    void OnItemUnslotted(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void OnItemSlotted(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void K2_BlueprintSaveDataReplicated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetTotalItemAmounts();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetConsumedItemAmounts();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityToggleMegastructureProductionMode();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetMegastructureProductionMode(bool bEnabled);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetMegastructureItemType(TSubclassOf<UItemType> ItemType);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityResetSatisfiedTier(AActor* destroyedMegastructure);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityHideIndicators();
    
};

