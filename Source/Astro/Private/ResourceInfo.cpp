#include "ResourceInfo.h"
#include "Templates/SubclassOf.h"
#include "AdaptiveTickComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent

class UItemType;
class UPrimitiveComponent;


void AResourceInfo::SetPrimaryItemTypeAndStoredSubType(TSubclassOf<UItemType> primaryItemType, TSubclassOf<UItemType> storedSubType) {
}


void AResourceInfo::MeshCursorEnd(UPrimitiveComponent* Component) {
}

void AResourceInfo::MeshCursorBegin(UPrimitiveComponent* Component) {
}

void AResourceInfo::MeshClicked(UPrimitiveComponent* Component, FKey Key) {
}

AResourceInfo::AResourceInfo() {
    this->AdaptiveTick = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("Adaptive Tick"));
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
    this->ItemType = NULL;
    this->storedSubItemType = NULL;
    this->Hovering = false;
    this->ItemParent = NULL;
    this->ActorParent = NULL;
    this->OffsetDistance = 75.00f;
}

