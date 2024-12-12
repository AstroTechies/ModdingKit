#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroDatumRef.h"
#include "AttachedResearchSubject.h"
#include "OnActiveResearchSubjectExpiredDelegate.h"
#include "OnActiveResearchSubjectsChangedDelegate.h"
#include "OnResearchSubjectListChangedDelegate.h"
#include "ResearchReplicationData.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "ActorResearchComponent.generated.h"

class APlayController;
class UCurveFloat;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorResearchComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnWantsToResearchChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnIsResearchingChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResearchSubjectListChanged OnResearchSubjectListChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnResearchReplicationDataChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnResearchStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveResearchSubjectsChanged OnAuthorityChangedActiveResearchSubjects;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveResearchSubjectExpired OnActiveResearchSubjectExpiredAuthority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ResearchSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResearchPowerRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumResearchPowerFraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumResearchRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* UnderPoweredResearchRateCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumResearchPowerMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumResearchRateMutliplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* OverPoweredResearchRateCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResearchSlotsUnclickableWhileActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyActiveResearchSubjectsOnInterruption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpiredResearchSubjectDestructionDelay;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ResearchData, meta=(AllowPrivateAccess=true))
    FResearchReplicationData ResearchReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ResearchSlotRefs;
    
public:
    UActorResearchComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void OnRep_ResearchData();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityStartOrInterruptResearch(APlayController* InstigatingController);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityChangedActiveResearchSubjects(FAstroDatumRef ResearchComponentRef, const TArray<FAttachedResearchSubject>& ActiveResearchSubjects);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityActiveResearchSubjectExpired(FAstroDatumRef ResearchComponentRef, FAttachedResearchSubject ExpiredAttachedResearchSubject);
    
};

