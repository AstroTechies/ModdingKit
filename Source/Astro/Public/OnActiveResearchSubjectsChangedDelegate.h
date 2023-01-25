#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AttachedResearchSubject.h"
#include "OnActiveResearchSubjectsChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveResearchSubjectsChanged, FAstroDatumRef, ResearchComponentRef, const TArray<FAttachedResearchSubject>&, ActiveResearchSubjects);

