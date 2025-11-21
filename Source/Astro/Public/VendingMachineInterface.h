#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SubclassOf.h"
#include "VendingMachineInterface.generated.h"

class APhysicalItem;

UINTERFACE(Blueprintable)
class UVendingMachineInterface : public UInterface {
    GENERATED_BODY()
};

class IVendingMachineInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<TSubclassOf<APhysicalItem>> GetVendingMachineBlueprints() const;
    
};

