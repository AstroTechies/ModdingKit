#include "PlacementVariant.h"

FPlacementVariant::FPlacementVariant() {
    this->SelectionWeight = 0.00f;
    this->WeightFalloff = 0.00f;
    this->Orientation = EPlacementOrientation::AlignToSurfaceNormal;
    this->RandomYaw = 0.00f;
    this->RandomPitch = 0.00f;
    this->bUniformScale = false;
    this->ExclusionRadius = 0.00f;
    this->SurfaceOffset = 0.00f;
    this->MaxDepenetrationVelocity = 0.00f;
    this->bEnableDensityScaling = false;
    this->bCastShadow = false;
    this->bCastShadowAsTwoSided = false;
    this->bReceivesDecals = false;
    this->bUseAsOccluder = false;
    this->bShouldOverrideDestructionEffects = false;
}

