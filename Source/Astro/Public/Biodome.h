#pragma once
#include "CoreMinimal.h"
#include "BiodomeSection.h"
#include "MegaStructure.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Biodome.generated.h"

class AAstroMissionsManager;
class APhysicalItem;
class UBiodomePlantComponent;
class UPowerComponent;
class UPrimitiveComponent;
class USceneComponent;
class USplineComponent;

UCLASS(Blueprintable)
class ASTRO_API ABiodome : public AMegaStructure {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLitChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnGrowBonusChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> MegaModuleSlots;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<APhysicalItem>, FName> EmplacedMegaModules;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<APhysicalItem>, FName> SetMegaModules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_BiodomeSections, meta=(AllowPrivateAccess=true))
    TArray<FBiodomeSection> BiodomeSections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SeedSectionSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LitThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 GrowLampStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OnLitChanged, meta=(AllowPrivateAccess=true))
    uint8 bIsLit: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsGrowBonusActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_GrowBonus, meta=(AllowPrivateAccess=true))
    float GrowBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultGrowBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrowLampPowerRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPowerFufillmentMultiplier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroMissionsManager* MissionsManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* sunDetector;
    
public:
    ABiodome(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetSunDetector(USceneComponent* NewSunDetector);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBiodomeSection(FBiodomeSection& sectionToRemove);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSeedSetInSlot(APhysicalItem* Seed);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_OnLitChanged() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_GrowBonus() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_BiodomeSections();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPlantSpawnedInBiodome(FSlotReference Slot, UBiodomePlantComponent* plant);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlantHarvested(UBiodomePlantComponent* plant, TArray<APhysicalItem*> Resources);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemUnemplacedInSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemUnemplacedFromMegamoduleSlot(const FSlotReference& Slot);
    
    UFUNCTION(BlueprintCallable)
    void OnItemSetInSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemSetInMegamoduleSlot(const FSlotReference& Slot);
    
    UFUNCTION(BlueprintCallable)
    void OnItemReleasedFromSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemReleasedFromMegamoduleSlot(const FSlotReference& Slot);
    
    UFUNCTION(BlueprintCallable)
    void OnItemEmplacedInSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemEmplacedInMegamoduleSlot(const FSlotReference& Slot);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetGrowBonusToBiodome(bool IsActive);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddSlotToBiodomeSection(int32 SectionIndex, FSlotReference Slot, USceneComponent* SectionMidpoint, UPrimitiveComponent* canopyCollision);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddExtensionToBiodomeSections(FBiodomeSection& sectionToAdd);
    
};

