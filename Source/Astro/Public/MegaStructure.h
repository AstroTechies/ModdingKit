#pragma once
#include "CoreMinimal.h"
#include "OnMegastructureStageChangedDelegate.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "VendingMachineInterface.h"
#include "MegaStructure.generated.h"

class UDamageComponent;

UCLASS(Blueprintable)
class ASTRO_API AMegaStructure : public APhysicalItem, public IVendingMachineInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMegastructureStageChanged OnMegastructureStageChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRegisterToManager: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MegastructureStageChanged, meta=(AllowPrivateAccess=true))
    int32 REP_MegastructureStage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APhysicalItem>> VendingMachineBlueprints;
    
public:
    AMegaStructure(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void OnTerrainGenerated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_MegastructureStageChanged() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandlePostSpawn();
    

    // Fix for true pure virtual functions not being implemented
};

