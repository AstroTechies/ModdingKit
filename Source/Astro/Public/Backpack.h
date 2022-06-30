#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "SlotReference.h"
#include "BackpackOxygenTankOverride.h"
#include "BackpackOxygenTankProperties.h"
#include "UObject/NoExportTypes.h"
#include "Backpack.generated.h"

class ADeformTool;
class UDistanceLightFaderComponent;
class ADroneBase;
class UCrackableActorComponent;
class UPointLightComponent;
class UMaterialInterface;
class UChildActorComponent;
class APhysicalItem;
class AAstroCharacter;

UCLASS(Blueprintable, Blueprintable)
class ABackpack : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> AuxResourceAndDeformToolSlots;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_CreativeDrone, meta = (AllowPrivateAccess = true))
    ADroneBase *CreativeDrone;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ADroneBase> CreativeDroneClass;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference CreativeDroneSlot;

    UPROPERTY(Export, Transient)
    UPointLightComponent *VirtualLightComponent;

    UPROPERTY(Export, Replicated)
    TArray<TWeakObjectPtr<UDistanceLightFaderComponent>> AttachedLights;

protected:
    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UMaterialInterface *PendingDronePaletteMaterial;

private:
    UPROPERTY(Export, Transient)
    UCrackableActorComponent *CatalogCrackable;

    UPROPERTY(Export, Transient)
    UCrackableActorComponent *CatalogCrackableCreative;

    UPROPERTY(Export, Transient)
    UCrackableActorComponent *MissionLogCrackable;

    UPROPERTY(Transient)
    ADeformTool *CachedDeformTool;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_Catalog)
    AActor *CatalogActor;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_MissionLog)
    AActor *MissionLogActor;

    UPROPERTY(Transient)
    AActor *CatalogActorPrev;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_Catalog)
    AActor *CatalogCreativeActor;

    UPROPERTY(Transient)
    AActor *CatalogCreativeActorPrev;

    UPROPERTY(EditAnywhere)
    FBackpackOxygenTankProperties DefaultOxygenTankProperties;

    UPROPERTY(SaveGame, ReplicatedUsing = OnOxygenTankPropertiesChanged)
    FBackpackOxygenTankOverride OxygenTankPropertiesOverride;

public:
    ABackpack();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void ToggleOpen();

    UFUNCTION(BlueprintCallable)
    void SetOpen(bool IsOpen);

    UFUNCTION(BlueprintCallable)
    void SetMissionLog(UChildActorComponent *missionLog);

    UFUNCTION(BlueprintCallable)
    void SetCatalog(UChildActorComponent *Catalog, UChildActorComponent *catalogCreative);

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
    void OnItemInSlotChanged(APhysicalItem *Item);

    UFUNCTION()
    void OnDeformToolEquippedStateChanged(bool equipped);

public:
    UFUNCTION()
    void OnCreativeModeEnabledChanged(bool bIsCreativeModeEnabled);

private:
    UFUNCTION()
    void OnCancel();

    UFUNCTION()
    void OnBackpackAttachedDisplayCrackedChanged(UCrackableActorComponent *CrackableActorComponent, bool cracked);

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
    bool GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, FVector &OutUnbundleOrigin);

    UFUNCTION(BlueprintPure)
    FBackpackOxygenTankProperties GetOxygenTankProperties() const;

    UFUNCTION(BlueprintCallable)
    bool GetOpen();

    UFUNCTION(BlueprintPure)
    AActor *GetInactiveChildCatalog();

    UFUNCTION(BlueprintPure)
    AActor *GetChildMissionLog();

    UFUNCTION(BlueprintPure)
    AActor *GetChildCatalog();

    UFUNCTION(BlueprintPure)
    AAstroCharacter *GetCharacter();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRemoveOxygenTankPropertiesOverride();

protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityAttemptToSpawnCreativeDrone();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityApplyOxygenTankPropertiesOverride(const FBackpackOxygenTankProperties &OverrideProperties);
};
