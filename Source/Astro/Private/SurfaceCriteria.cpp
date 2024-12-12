#include "SurfaceCriteria.h"

FSurfaceCriteria::FSurfaceCriteria() {
    this->NormalMode = ESurfaceCriteriaNormalMode::Any;
    this->SkyMode = ESurfaceCriteriaSkyMode::Any;
    this->NormalThreshold = 0.00f;
}

