#pragma once
#include "CoreMinimal.h"
#include "OnActiveResearchSubjectsChangedDelegate.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "OnResearchSubjectListChangedDelegate.h"
#include "OnActiveResearchSubjectExpiredDelegate.h"
#include "ResearchReplicationData.h"
#include "AstroDatumRef.h"
#include "AttachedResearchSubject.h"
#include "ActorResearchComponent.generated.h"

class UCurveFloat;
class APlayController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorResearchComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnWantsToResearchChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnIsResearchingChanged;

    UPROPERTY(BlueprintAssignable)
    FOnResearchSubjectListChanged OnResearchSubjectListChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnResearchReplicationDataChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnResearchStateChanged;

    UPROPERTY(BlueprintAssignable)
    FOnActiveResearchSubjectsChanged OnAuthorityChangedActiveResearchSubjects;

    UPROPERTY(BlueprintAssignable)
    FOnActiveResearchSubjectExpired OnActiveResearchSubjectExpiredAuthority;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ResearchSlotNames;

    UPROPERTY(EditDefaultsOnly)
    float ResearchPowerRequired;

    UPROPERTY(EditDefaultsOnly)
    float MinimumResearchPowerFraction;

    UPROPERTY(EditDefaultsOnly)
    float MinimumResearchRateMultiplier;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *UnderPoweredResearchRateCurve;

    UPROPERTY(EditDefaultsOnly)
    float MaximumResearchPowerMultiplier;

    UPROPERTY(EditDefaultsOnly)
    float MaximumResearchRateMutliplier;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *OverPoweredResearchRateCurve;

    UPROPERTY(EditDefaultsOnly)
    bool bResearchSlotsUnclickableWhileActive;

    UPROPERTY(EditDefaultsOnly)
    bool bDestroyActiveResearchSubjectsOnInterruption;

    UPROPERTY(EditDefaultsOnly)
    float ExpiredResearchSubjectDestructionDelay;

protected:
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = OnRep_ResearchData, meta = (AllowPrivateAccess = true))
    FResearchReplicationData ResearchReplicationData;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ResearchSlotRefs;

public:
    UActorResearchComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_ResearchData();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityStartOrInterruptResearch(APlayController *InstigatingController);

    UFUNCTION()
    void AuthorityChangedActiveResearchSubjects(FAstroDatumRef ResearchComponentRef, const TArray<FAttachedResearchSubject> &ActiveResearchSubjects);

    UFUNCTION()
    void AuthorityActiveResearchSubjectExpired(FAstroDatumRef ResearchComponentRef, FAttachedResearchSubject ExpiredAttachedResearchSubject);
};
