#include "AstroFoliageActor.h"
#include "Components/SceneComponent.h"

AAstroFoliageActor::AAstroFoliageActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("FoliageRootComponent"));
}


