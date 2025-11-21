#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EPlantLifeStage.h"
#include "OnGrowBonusChangedDelegate.h"
#include "PlantDropList.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "BiodomePlantComponent.generated.h"

class ABiodome;
class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UBiodomePlantComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnApplyFertilisedVisualChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlantLifeStage, FPlantDropList> ResourcesToDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlantLifeStage, int32> SeedDropCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SlotReference;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_LifeStageChanged, meta=(AllowPrivateAccess=true))
    EPlantLifeStage CurrentLifeStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bPlantedInBiodome: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bTimerActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsGrowBonusActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToFullyGrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToWilt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToDie;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EmoteBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float TimeElapsed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float TimeToUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentGrowRate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlantHarvested;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnWilting;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGrowBonusChanged OnGrowBonusChanged;
    
public:
    UBiodomePlantComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetTimeToFullyGrow(const int32 newTimeToFullyGrow);
    
    UFUNCTION(BlueprintCallable)
    void ResourcesDropped(TArray<APhysicalItem*> physicalItems);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_LifeStageChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeToDie() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlotReference GetSlotReference() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSeedDropCountForStage(EPlantLifeStage lifeStage) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlantedInBiodome() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSubclassOf<UItemType>> GetPlantDropForStage(EPlantLifeStage lifeStage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPlantLifeStage GetLifeStage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEmoteBonus() const;
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentActiveTimerRemainingTime();
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySetSlotReference(FSlotReference newSlotReference);
    
    UFUNCTION(BlueprintCallable)
    bool AuthoritySetPlantedInBiodome(const bool bIsInBiodome);
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySetLifeStage(EPlantLifeStage newLifeStage);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetGrowBonus(const ABiodome* Biodome, const bool isBonusActive);
    
    UFUNCTION(BlueprintCallable)
    void AddBonusToCurrentActiveTimer(const float bonusToAdd);
    
};

