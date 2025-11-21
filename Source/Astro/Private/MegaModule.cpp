#include "MegaModule.h"
#include "DamageComponent.h"

AMegaModule::AMegaModule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
}






