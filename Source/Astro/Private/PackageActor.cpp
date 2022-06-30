#include "PackageActor.h"
#include "AstroActionComponent.h"


APackageActor::APackageActor() {
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
}

