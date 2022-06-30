#pragma once
#include "CoreMinimal.h"
#include "ResearchSubjectReplicationData.h"
#include "OnResearchSubjectListChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResearchSubjectListChanged, const TArray<FResearchSubjectReplicationData>&, CurrentResearchSubjects, const TArray<FResearchSubjectReplicationData>&, PrevResearchSubjects);

