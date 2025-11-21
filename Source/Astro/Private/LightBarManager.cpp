#include "LightBarManager.h"

ULightBarManager::ULightBarManager() {
}

bool ULightBarManager::UpdateColorOfLightBarRequest(const FName LightBarID, const FLinearColor LightBarColour) {
    return false;
}

bool ULightBarManager::UpdateColorCurveOfLightBarRequest(const FName LightBarID, UCurveLinearColor* LightBarColorCurve) {
    return false;
}

bool ULightBarManager::ResetLightbarState() {
    return false;
}

bool ULightBarManager::RemoveLightBarRequest(const FName LightBarID) {
    return false;
}

bool ULightBarManager::DoesLightBarRequestExist(const FName LightBarID) {
    return false;
}

bool ULightBarManager::AddLightBarColorRequestByCurve(const FName LightBarID, const uint8 LightBarPriority, UCurveLinearColor* LightBarColorCurve, const bool bIsLooping) {
    return false;
}

bool ULightBarManager::AddLightBarColorRequestByColor(const FName LightBarID, const uint8 LightBarPriority, const FLinearColor LightBarColour, const bool bIsLooping, const float MaxTime, const bool bIsPulsating) {
    return false;
}

bool ULightBarManager::AddLightBarColorRequest(const FAstroLightBarData& LightBarData) {
    return false;
}


