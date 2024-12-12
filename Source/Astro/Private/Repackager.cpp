#include "Repackager.h"
#include "AstroActionComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

ARepackager::ARepackager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
    this->TargetState = ERepackagingTargetState::None;
    this->RepackActionType = NULL;
}

void ARepackager::UpdateRepackagingTarget() {
}



void ARepackager::OnAttachedItemStoredItemTypeChanged(UItemComponent* changedItemComponent, TSubclassOf<UItemType> NewItemType) {
}

void ARepackager::InitiateRepackaging() {
}

void ARepackager::HandleRepackagingTargetEndPlay(AActor* Actor) {
}

void ARepackager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARepackager, TargetState);
}


