#include "TerrainBrush.h"

ATerrainBrush::ATerrainBrush(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveOperation = EDeformType::Subtract;
    this->LastTerrainHardness = 0;
    this->BrushIndicatorScale = 0.01f;
    this->BrushIndicatorIntensity = 0.00f;
    this->BrushIndicatorUsing = 0.00f;
    this->bBrushIndicatorCanUse = false;
    this->TargetComponent = NULL;
    this->PlayerAccentIndex = 0;
    this->GaugePercent = 0.00f;
    this->GaugeCapacity = 0.00f;
    this->LowSedimentThreshold = 0.00f;
    this->DeformEffectComponent = NULL;
    this->BrushDiscMaterial = NULL;
    this->HardnessTextureLevel0 = NULL;
    this->HardnessTextureLevel1 = NULL;
    this->HardnessTextureLevel2 = NULL;
    this->HardnessTextureLevel3 = NULL;
    this->FlattenGridTexture = NULL;
    this->IsLocalBrush = false;
    this->ResourceNodeTooltipBadgeAutoCollapseDelay = 0.10f;
    this->ResourceNodeTooltipDetailsAutoExpandDelay = 0.50f;
    this->CursorDetailsExpansionMovementTolerance = 1.00f;
    this->ThrottledNativeTickInterval = 0.10f;
    this->ResourceNodeTooltipComponent = NULL;
    this->CurrentItemTypeForResourceTooltip = NULL;
    this->AddBrushComponent = NULL;
    this->SubtractBrushComponent = NULL;
    this->FlatBrushComponent = NULL;
    this->ColorPickerBrushComponent = NULL;
    this->ColorPaintBrushComponent = NULL;
}

void ATerrainBrush::ShowBrushElements(EDeformType deformType, bool showElement) {
}

void ATerrainBrush::SetResourceTooltipSuppression(bool SuppressResourceTooltip) {
}




void ATerrainBrush::ManageTerrainHardnessTexture() {
}


void ATerrainBrush::ChangeBrushOperation(EDeformType NewType) {
}


