#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TetherNetwork.generated.h"

class ASlotConnection;
class UTetherAttachComponent;
class UTetherNetwork;
class UOxygenatorComponent;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UTetherNetwork : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool hasOxygen;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool HaveConnectedOxygen;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<UTetherAttachComponent *> AttachNodes;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<UTetherNetwork *> ConnectedOxygenProviderNetworks;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<UTetherNetwork *> ConnectedTetherPostNetworks;

private:
    UPROPERTY(Export, Transient)
    TArray<UOxygenatorComponent *> Oxygenators;

public:
    UTetherNetwork();
    UFUNCTION()
    void RemoveOxygenator(UOxygenatorComponent *oxygenator);

    UFUNCTION(BlueprintCallable)
    static void OnTetherConnectionDestroyed(const ASlotConnection *Connection);

    UFUNCTION()
    void OnOxygenatorSupplyingOxygenChanged(UOxygenatorComponent *oxygenator);

    UFUNCTION(BlueprintPure)
    bool IsSupplyingOxygenToConsumers();
};
