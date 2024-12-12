#include "ViewTargetBlendParams.h"

FViewTargetBlendParams::FViewTargetBlendParams() {
    this->BlendTime = 0.00f;
    this->BlendExponent = 0.00f;
    this->BlendFunction = VTBlend_Linear;
    this->bLockOutgoing = false;
}

