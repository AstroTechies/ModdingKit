#include "ResourceInfo.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AdaptiveTickComponent.h"
#include "Templates/SubclassOf.h"

AResourceInfo::AResourceInfo(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->AdaptiveTick = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("Adaptive Tick"));
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
    this->ItemType = NULL;
    this->storedSubItemType = NULL;
    this->Hovering = false;
    this->ItemParent = NULL;
    this->ActorParent = NULL;
    this->OffsetDistance = 75.00f;
    this->StaticMesh->SetupAttachment(RootComponent);
}


void AResourceInfo::SetPrimaryItemTypeAndStoredSubType(TSubclassOf<UItemType> primaryItemType, TSubclassOf<UItemType> storedSubType) {
}


void AResourceInfo::MeshCursorEnd(UPrimitiveComponent* Component) {
}

void AResourceInfo::MeshCursorBegin(UPrimitiveComponent* Component) {
}

void AResourceInfo::MeshClicked(UPrimitiveComponent* Component, FKey Key) {
}


