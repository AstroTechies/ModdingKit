#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "TetherNetwork.generated.h"

class ASlotConnection;
class UTetherAttachComponent;
class UTetherNetwork;
class UOxygenatorComponent;

UCLASS(Blueprintable)
class ASTRO_API UTetherNetwork : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool hasOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HaveConnectedOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UTetherAttachComponent*> AttachNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTetherNetwork*> ConnectedOxygenProviderNetworks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTetherNetwork*> ConnectedTetherPostNetworks;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UOxygenatorComponent*> Oxygenators;
    
public:
    UTetherNetwork();
    UFUNCTION()
    void RemoveOxygenator(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintCallable)
    static void OnTetherConnectionDestroyed(const ASlotConnection* Connection);
    
    UFUNCTION()
    void OnOxygenatorSupplyingOxygenChanged(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintPure)
    bool IsSupplyingOxygenToConsumers();
    
};

