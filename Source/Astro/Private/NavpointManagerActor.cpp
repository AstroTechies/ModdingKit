#include "NavpointManagerActor.h"
#include "Components/SceneComponent.h"
#include "NavpointManager.h"

ANavpointManagerActor::ANavpointManagerActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->NavpointManager = CreateDefaultSubobject<UNavpointManager>(TEXT("NavpointManager"));
}


