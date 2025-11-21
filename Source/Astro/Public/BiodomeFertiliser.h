#pragma once
#include "CoreMinimal.h"
#include "BiodomeModule.h"
#include "EBiodomeFertiliserState.h"
#include "ParticleStateChangedDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "BiodomeFertiliser.generated.h"

class APhysicalItem;
class UItemType;
class UParticleSystemComponent;
class UPowerComponent;

UCLASS(Blueprintable)
class ASTRO_API ABiodomeFertiliser : public ABiodomeModule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FParticleStateChanged OnParticleStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float REP_TimeElapsed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float TimeToCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FertiliserBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SprinklingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ResourceItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 REP_bHasResources: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 REP_bIsAttached: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OnCurrentStateChanged, meta=(AllowPrivateAccess=true))
    EBiodomeFertiliserState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* FertiliserParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference ResourcesSlotRef;
    
public:
    ABiodomeFertiliser(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetSprinkleParticle(UParticleSystemComponent* Particle);
    
    UFUNCTION(BlueprintCallable)
    void SetResourcesSlotRef(const FSlotReference& SlotRef);
    
    UFUNCTION(BlueprintCallable)
    void SetParticleState(bool NewState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_OnCurrentStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityOnSetResourceInSlot(APhysicalItem* slottedItem);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityOnReleasedResourceFromSlot(APhysicalItem* slottedItem);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityOnPowerStateChanged(bool bIsPowered);
    
};

