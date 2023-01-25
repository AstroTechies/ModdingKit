#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "TetherNetwork.generated.h"

class ASlotConnection;
class UOxygenatorComponent;
class UTetherAttachComponent;
class UTetherNetwork;

UCLASS(Blueprintable)
class ASTRO_API UTetherNetwork : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool hasOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HaveConnectedOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTetherAttachComponent*> AttachNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTetherNetwork*> ConnectedOxygenProviderNetworks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTetherNetwork*> ConnectedTetherPostNetworks;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UOxygenatorComponent*> Oxygenators;
    
public:
    UTetherNetwork();
    UFUNCTION(BlueprintCallable)
    void RemoveOxygenator(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintCallable)
    static void OnTetherConnectionDestroyed(const ASlotConnection* Connection);
    
    UFUNCTION(BlueprintCallable)
    void OnOxygenatorSupplyingOxygenChanged(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSupplyingOxygenToConsumers();
    
};

