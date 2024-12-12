#include "ResearchModuleControlPanel.h"

AResearchModuleControlPanel::AResearchModuleControlPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}


void AResearchModuleControlPanel::OnResearchSubjectListChanged(const TArray<FResearchSubjectReplicationData>& CurrentResearchSubjects, const TArray<FResearchSubjectReplicationData>& PrevResearchSubjects) {
}

void AResearchModuleControlPanel::OnResearchReplicationDataChanged() {
}

UActorResearchComponent* AResearchModuleControlPanel::GetControlledResearchComponent() const {
    return NULL;
}


