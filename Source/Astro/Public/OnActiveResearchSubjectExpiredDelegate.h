#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AttachedResearchSubject.h"
#include "OnActiveResearchSubjectExpiredDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveResearchSubjectExpired, FAstroDatumRef, ResearchComponentRef, FAttachedResearchSubject, ExpiredAttachedResearchSubject);

