#pragma once
#include "CoreMinimal.h"
#include "ResearchReplicationData.h"
#include "Blueprint/UserWidget.h"
#include "ResearchSubjectReplicationData.h"
#include "ResearchDisplayWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UResearchDisplayWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UResearchDisplayWidget();
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateForResearchSubjects(const TArray<FResearchSubjectReplicationData> &ResearchSubjects);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateForResearchData(const FResearchReplicationData &researchData);
};
