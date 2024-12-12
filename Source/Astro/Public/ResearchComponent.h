#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AttachedResearchSubject.h"
#include "OnActiveResearchSubjectExpiredDelegate.h"
#include "OnActiveResearchSubjectsChangedDelegate.h"
#include "SlotReference.h"
#include "ResearchComponent.generated.h"

USTRUCT(BlueprintType)
struct FResearchComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bWantsToResearch: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsResearching: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentPowerLevelRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentResearchRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAttachedResearchSubject> IncomingResearchSubjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAttachedResearchSubject> ActiveResearchSubjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAttachedResearchSubject> OutgoingResearchSubjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveResearchSubjectsChanged OnActiveResearchSubjectsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveResearchSubjectExpired OnActiveResearchSubjectExpired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ResearchSlots;
    
    ASTRO_API FResearchComponent();
};

