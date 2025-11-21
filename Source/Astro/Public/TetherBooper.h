#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "TetherBooper.generated.h"

class AAstroCharacter;
class AVehicleBase;
class UItemType;
class UPowerComponent;
class UStorageChassisComponent;
class UTetherAttachComponent;
class UTetherPostComponent;

UCLASS(Blueprintable)
class ATetherBooper : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* ChassisComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> TetherItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TetherAttachDistOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DropDistancePercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForgetLastTetherDelay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroCharacter* CurrentCharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OnEnableStateChanged, meta=(AllowPrivateAccess=true))
    bool bIsTurnedOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherPostComponent* LastPlacedTether;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* LocalAstroCharacterTetherAttachComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* LocalVehicleTetherAttachComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AVehicleBase> CurrentVehicle;
    
public:
    ATetherBooper(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void UpdateCharacterDrivingState();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerTurnOn();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerTurnOff();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerToggleEnabledState();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayTetherPlacedSFX();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_OnEnableStateChanged();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Multicast_PlayTetherPlacedSFX();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleOnPlacedInSlot();
    
};

