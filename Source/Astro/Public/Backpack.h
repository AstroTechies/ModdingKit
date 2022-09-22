#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "SlotReference.h"
#include "BackpackOxygenTankProperties.h"
#include "BackpackOxygenTankOverride.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Backpack.generated.h"

class UMaterialInterface;
class ADroneBase;
class UCrackableActorComponent;
class UPointLightComponent;
class ADeformTool;
class UDistanceLightFaderComponent;
class APhysicalItem;
class UChildActorComponent;
class AAstroCharacter;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPointLightComponent* VirtualLightComponent;
    
    UPROPERTY(EditAnywhere, Export, Replicated)
    TArray<TWeakObjectPtr<UDistanceLightFaderComponent>> AttachedLights;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PendingDronePaletteMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* CatalogCrackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* CatalogCrackableCreative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
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
    ABackpack();
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
    UFUNCTION()
    void OnRightAuxReleased();
    
    UFUNCTION()
    void OnRightAuxPressed();
    
    UFUNCTION()
    void OnRep_MissionLog();
    
    UFUNCTION()
    void OnRep_CreativeDrone();
    
    UFUNCTION()
    void OnRep_Catalog();
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnOxygenTankPropertiesChanged();
    
private:
    UFUNCTION()
    void OnLeftAuxReleased();
    
    UFUNCTION()
    void OnLeftAuxPressed();
    
    UFUNCTION()
    void OnItemInSlotChanged(APhysicalItem* Item);
    
    UFUNCTION()
    void OnDeformToolEquippedStateChanged(bool equipped);
    
public:
    UFUNCTION()
    void OnCreativeModeEnabledChanged(bool bIsCreativeModeEnabled);
    
private:
    UFUNCTION()
    void OnCancel();
    
    UFUNCTION()
    void OnBackpackAttachedDisplayCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool cracked);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsLocallyControlled();
    
private:
    UFUNCTION()
    void HandlePlayerDeathBegins();
    
    UFUNCTION()
    void HandleDroneFlightStateChanged();
    
public:
    UFUNCTION(BlueprintPure)
    bool GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, FVector& OutUnbundleOrigin);
    
    UFUNCTION(BlueprintPure)
    FBackpackOxygenTankProperties GetOxygenTankProperties() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetOpen();
    
    UFUNCTION(BlueprintPure)
    AActor* GetInactiveChildCatalog();
    
    UFUNCTION(BlueprintPure)
    AActor* GetChildMissionLog();
    
    UFUNCTION(BlueprintPure)
    AActor* GetChildCatalog();
    
    UFUNCTION(BlueprintPure)
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

