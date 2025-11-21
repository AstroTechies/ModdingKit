#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "MegaModule.generated.h"

class UDamageComponent;

UCLASS(Blueprintable)
class ASTRO_API AMegaModule : public APhysicalItem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    
public:
    AMegaModule(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModuleUnemplacedFromSlot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModuleReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModulePlacedInSlot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModuleEmplacedInSlot();
    
};

