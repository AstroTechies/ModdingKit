#include "DayNight.h"
#include "Net/UnrealNetwork.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkyLightComponent -FallbackName=SkyLightComponent

class UAstroSaveCustomArchiveProxy;

void ADayNight::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void ADayNight::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADayNight, ServerTimeStamp);
}

ADayNight::ADayNight() {
    this->SpaceAmbientIntensity = 0.50f;
    this->SolarSystemSpeed = 1.00f;
    this->SkyVisibility = 1.00f;
    this->ServerCorrectionTime = 1.00f;
    this->LockLocalBody = NULL;
    this->SkyLight = CreateDefaultSubobject<USkyLightComponent>(TEXT("Sky Light"));
    this->ServerTimeStamp = 0.00f;
    this->TargetSkyVisibility = 1.00f;
}

