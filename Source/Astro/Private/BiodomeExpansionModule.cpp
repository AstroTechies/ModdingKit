#include "BiodomeExpansionModule.h"
#include "Net/UnrealNetwork.h"

ABiodomeExpansionModule::ABiodomeExpansionModule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanPlace = true;
    this->bIsLocked = false;
}

void ABiodomeExpansionModule::SetCanPlace(bool newCanPlace) {
}

void ABiodomeExpansionModule::SetBiodomeSection(FBiodomeSection newBiodomeSection) {
}

void ABiodomeExpansionModule::OnRep_IsLocked() {
}

void ABiodomeExpansionModule::AuthorityToggleLock() {
}

void ABiodomeExpansionModule::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABiodomeExpansionModule, bIsLocked);
}


