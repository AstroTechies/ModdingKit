#pragma once
#include "CoreMinimal.h"
#include "PrinterComponent.h"
#include "Templates/SubclassOf.h"
#include "VendingMachinePrinterLogicComponent.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVendingMachinePrinterLogicComponent : public UPrinterComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Blueprints, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APhysicalItem>> REP_Blueprints;
    
public:
    UVendingMachinePrinterLogicComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void OnSpawnedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Blueprints();
    
};

