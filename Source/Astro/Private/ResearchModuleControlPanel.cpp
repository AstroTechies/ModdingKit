#include "ResearchModuleControlPanel.h"

class UActorResearchComponent;


void AResearchModuleControlPanel::OnResearchSubjectListChanged(const TArray<FResearchSubjectReplicationData>& CurrentResearchSubjects, const TArray<FResearchSubjectReplicationData>& PrevResearchSubjects) {
}

void AResearchModuleControlPanel::OnResearchReplicationDataChanged() {
}

UActorResearchComponent* AResearchModuleControlPanel::GetControlledResearchComponent() const {
    return NULL;
}

AResearchModuleControlPanel::AResearchModuleControlPanel() {
}

