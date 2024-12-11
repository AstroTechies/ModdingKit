#include "PackageActor.h"
#include "AstroActionComponent.h"

APackageActor::APackageActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
}



