#pragma once
#include "CoreMinimal.h"
#include "ResearchSubjectReplicationData.h"
#include "ControlPanel.h"
#include "ResearchReplicationData.h"
#include "ResearchModuleControlPanel.generated.h"

class UResearchDisplayWidgetComponent;
class UActorResearchComponent;

UCLASS(Blueprintable)
class ASTRO_API AResearchModuleControlPanel : public AControlPanel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UResearchDisplayWidgetComponent*> ResearchDisplayComponents;
    
public:
    AResearchModuleControlPanel();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateForNewResearchReplicationData(const FResearchReplicationData& ReplicationData);
    
    UFUNCTION()
    void OnResearchSubjectListChanged(const TArray<FResearchSubjectReplicationData>& CurrentResearchSubjects, const TArray<FResearchSubjectReplicationData>& PrevResearchSubjects);
    
    UFUNCTION()
    void OnResearchReplicationDataChanged();
    
    UFUNCTION(BlueprintPure)
    UActorResearchComponent* GetControlledResearchComponent() const;
    
};

