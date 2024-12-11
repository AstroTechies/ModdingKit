#pragma once
#include "CoreMinimal.h"
#include "ControlPanel.h"
#include "ResearchReplicationData.h"
#include "ResearchSubjectReplicationData.h"
#include "ResearchModuleControlPanel.generated.h"

class UActorResearchComponent;
class UResearchDisplayWidgetComponent;

UCLASS(Blueprintable)
class ASTRO_API AResearchModuleControlPanel : public AControlPanel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UResearchDisplayWidgetComponent*> ResearchDisplayComponents;
    
public:
    AResearchModuleControlPanel(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateForNewResearchReplicationData(const FResearchReplicationData& ReplicationData);
    
    UFUNCTION(BlueprintCallable)
    void OnResearchSubjectListChanged(const TArray<FResearchSubjectReplicationData>& CurrentResearchSubjects, const TArray<FResearchSubjectReplicationData>& PrevResearchSubjects);
    
    UFUNCTION(BlueprintCallable)
    void OnResearchReplicationDataChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorResearchComponent* GetControlledResearchComponent() const;
    
};

