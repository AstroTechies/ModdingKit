#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "ResearchSubjectReplicationData.h"
#include "ResearchReplicationData.h"
#include "Blueprint/UserWidget.h"
#include "ResearchDisplayWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UResearchDisplayWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UResearchDisplayWidget();
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateForResearchSubjects(const TArray<FResearchSubjectReplicationData>& ResearchSubjects);
    
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateForResearchData(const FResearchReplicationData& researchData);
    
};

