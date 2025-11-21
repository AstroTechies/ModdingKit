#include "DisplayCaseShelf.h"
#include "StorageChassisComponent.h"

ADisplayCaseShelf::ADisplayCaseShelf(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SlotOrganizationRule = NULL;
    this->StorageChassis = CreateDefaultSubobject<UStorageChassisComponent>(TEXT("StorageChassis"));
}

void ADisplayCaseShelf::AuthorityOnSetItem(APhysicalItem* inPhysicalItem) {
}

void ADisplayCaseShelf::AuthorityOnReleaseItem(APhysicalItem* inPhysicalItem) {
}


