#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "SlotReference.h"
#include "AttachedResearchSubject.generated.h"

USTRUCT(BlueprintType)
struct FAttachedResearchSubject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef ResearchSubjectComponentRef;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference ResearchSlotRef;
    
    ASTRO_API FAttachedResearchSubject();
};

