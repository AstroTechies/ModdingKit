#include "AstroAIPawn.h"
#include "AstroActionComponent.h"

AAstroAIPawn::AAstroAIPawn() {
    this->TargetingOriginNode = NULL;
    this->AttackOriginNode = NULL;
    this->CalculateAttackRotatorOnlyInZ = true;
    this->IsWarning = false;
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
}

