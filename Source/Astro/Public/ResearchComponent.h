#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AttachedResearchSubject.h"
#include "OnActiveResearchSubjectsChangedDelegate.h"
#include "OnActiveResearchSubjectExpiredDelegate.h"
#include "SlotReference.h"
#include "ResearchComponent.generated.h"

USTRUCT(BlueprintType)
struct FResearchComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bWantsToResearch: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bIsResearching: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentPowerLevelRatio;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentResearchRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FAttachedResearchSubject> IncomingResearchSubjects;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAttachedResearchSubject> ActiveResearchSubjects;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FAttachedResearchSubject> OutgoingResearchSubjects;
    
    UPROPERTY()
    FOnActiveResearchSubjectsChanged OnActiveResearchSubjectsChanged;
    
    UPROPERTY()
    FOnActiveResearchSubjectExpired OnActiveResearchSubjectExpired;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ResearchSlots;
    
    ASTRO_API FResearchComponent();
};

