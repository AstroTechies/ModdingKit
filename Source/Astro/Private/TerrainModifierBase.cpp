#include "TerrainModifierBase.h"

UTerrainModifierBase::UTerrainModifierBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bVisible = false;
    this->Enabled = true;
    this->SeedOffset = 0;
    this->EvaluationDepth = 0;
    this->EdgeEvaluationDepth = 0;
}


