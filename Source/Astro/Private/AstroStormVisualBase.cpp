#include "AstroStormVisualBase.h"

AAstroStormVisualBase::AAstroStormVisualBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsLocalPlayerRelevant = false;
    this->StormID = 0;
    this->OuterGameplayRadius = 0.00f;
    this->InnerGameplayRadius = 0.00f;
    this->PlayerGameplayRadius = 0.00f;
    this->OuterEdgeFogRadius = 0.00f;
    this->InnerEdgeFogRadius = 0.00f;
    this->OuterEyeFogRadius = 0.00f;
    this->InnerEyeFogRadius = 0.00f;
    this->InStormFogMaxOpacity = 0.00f;
    this->EyeFogMaxOpacity = 0.00f;
    this->InStormFogDensity = 0.00f;
    this->EyeFogDensity = 0.00f;
    this->PlayerFogRadius = 0.00f;
    this->PlayerGlitchWallApproachDistance = 0.00f;
    this->IsSpinningUp = false;
    this->IsSpinningDown = false;
}





float AAstroStormVisualBase::GetPlayerLocationFogMaxOpacity() {
    return 0.0f;
}

float AAstroStormVisualBase::GetPlayerLocationFogDensity() {
    return 0.0f;
}


