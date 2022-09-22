#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OxygenatorSignalDelegate.h"
#include "OxygenatorComponent.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UOxygenatorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenatorSignal OnSupplyingOxygenChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenatorSignal OnOxygenatorEndPlay;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRequiresPower: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSuppliesOxygenToContainedCharactersOnly: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsSupplyingOxygen, meta=(AllowPrivateAccess=true))
    uint8 bIsSupplyingOxygen: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsOxygenSupplyEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwnerItem;
    
public:
    UOxygenatorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_IsSupplyingOxygen();
    
    UFUNCTION()
    void OnOwnerNotFullyPowered();
    
    UFUNCTION()
    void OnOwnerItemRemovedFromSlot(bool bNewOwner);
    
    UFUNCTION()
    void OnOwnerItemPlacedInSlot();
    
    UFUNCTION()
    void OnOwnerFullyPowered();
    
    UFUNCTION()
    void OnItemPadSpawned();
    
    UFUNCTION()
    void OnItemPadDestroyed();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOxygenSupplyEnabled(bool bSupplyEnabled);
    
};

