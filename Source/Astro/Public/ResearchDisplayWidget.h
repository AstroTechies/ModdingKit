#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ResearchReplicationData.h"
#include "ResearchSubjectReplicationData.h"
#include "ResearchDisplayWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UResearchDisplayWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UResearchDisplayWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateForResearchSubjects(const TArray<FResearchSubjectReplicationData>& ResearchSubjects);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateForResearchData(const FResearchReplicationData& researchData);
    
};

