#include "AxisOffsetConstraintModifier.h"

UAxisOffsetConstraintModifier::UAxisOffsetConstraintModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bConstrainForward = false;
    this->bConstrainUp = false;
    this->bConstrainRight = false;
    this->ForwardMax = 0.00f;
    this->ForwardMin = 0.00f;
    this->ForwardCorrectionSpeed = 0.00f;
    this->UpMax = 0.00f;
    this->UpMin = 0.00f;
    this->UpCorrectionSpeed = 0.00f;
    this->RightMax = 0.00f;
    this->RightMin = 0.00f;
    this->RightCorrectionSpeed = 0.00f;
}


