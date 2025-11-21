#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "BackpackOxygenTankOverride.h"
#include "BackpackOxygenTankProperties.h"
#include "EDonationReward.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "Backpack.generated.h"

class AAstroCharacter;
class ADeformTool;
class ADroneBase;
class APhysicalItem;
class UChildActorComponent;
class UCrackableActorComponent;
class UDistanceLightFaderComponent;
class UMaterialInterface;
class UPointLightComponent;

UCLASS(Blueprintable)
class ABackpack : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> AuxResourceAndDeformToolSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CreativeDrone, meta=(AllowPrivateAccess=true))
    ADroneBase* CreativeDrone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADroneBase> CreativeDroneClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference CreativeDroneSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPointLightComponent* VirtualLightComponent;
    
    UPROPERTY(EditAnywhere, Export, Replicated, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UDistanceLightFaderComponent>> AttachedLights;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PendingDronePaletteMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* CatalogCrackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* CatalogCrackableCreative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* MissionLogCrackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADeformTool* CachedDeformTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Catalog, meta=(AllowPrivateAccess=true))
    AActor* CatalogActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_MissionLog, meta=(AllowPrivateAccess=true))
    AActor* MissionLogActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CatalogActorPrev;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Catalog, meta=(AllowPrivateAccess=true))
    AActor* CatalogCreativeActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CatalogCreativeActorPrev;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBackpackOxygenTankProperties DefaultOxygenTankProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnOxygenTankPropertiesChanged, meta=(AllowPrivateAccess=true))
    FBackpackOxygenTankOverride OxygenTankPropertiesOverride;
    
public:
    ABackpack(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void ToggleOpen();
    
    UFUNCTION(BlueprintCallable)
    void SetOpen(bool IsOpen);
    
    UFUNCTION(BlueprintCallable)
    void SetMissionLog(UChildActorComponent* missionLog);
    
    UFUNCTION(BlueprintCallable)
    void SetCatalog(UChildActorComponent* Catalog, UChildActorComponent* catalogCreative);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRightAuxReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnRightAuxPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MissionLog();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CreativeDrone();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Catalog();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOxygenTankPropertiesChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnMuseumPowerSatisfactionChanged(const float inPowerSatisfaction);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLeftAuxReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnLeftAuxPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnItemInSlotChanged(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDonationRewardsChanged(const EDonationReward rewardTypeChanged);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDeformToolEquippedStateChanged(bool equipped);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCreativeModeEnabledChanged(bool bIsCreativeModeEnabled);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCancel();
    
    UFUNCTION(BlueprintCallable)
    void OnBackpackAttachedDisplayCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool cracked);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandlePlayerDeathBegins();
    
    UFUNCTION(BlueprintCallable)
    void HandleDroneFlightStateChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, FVector& OutUnbundleOrigin);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBackpackOxygenTankProperties GetOxygenTankProperties() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetOpen();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInactiveChildCatalog();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetChildMissionLog();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetChildCatalog();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroCharacter* GetCharacter();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRemoveOxygenTankPropertiesOverride();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityAttemptToSpawnCreativeDrone();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityApplyOxygenTankPropertiesOverride(const FBackpackOxygenTankProperties& OverrideProperties);
    
};

