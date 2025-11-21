#include "StormSpawnedLocalPointFXConfig.h"

FStormSpawnedLocalPointFXConfig::FStormSpawnedLocalPointFXConfig() {
    this->ParticleTemplate = NULL;
    this->InnerGameplayRadiusSpawnOffset = 0.00f;
    this->OuterGameplayRadiusSpawnOffset = 0.00f;
    this->Radius = 0.00f;
    this->Scale = 0.00f;
    this->Lifetime = 0.00f;
    this->BaseSpawnDelay = 0.00f;
    this->BaseSpawnDelayVariance = 0.00f;
    this->maxCount = 0;
    this->AlignWorldUp = false;
    this->IsRubyHarvestPoint = false;
    this->RubyHarvestRadius = 0.00f;
    this->RubyHarvestScalar = 0.00f;
    this->DebugDrawRubyHarvestArea = false;
}

