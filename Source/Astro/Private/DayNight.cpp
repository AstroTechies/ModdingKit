#include "DayNight.h"
#include "Components/SkyLightComponent.h"
#include "Net/UnrealNetwork.h"

ADayNight::ADayNight(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->SpaceAmbientIntensity = 0.50f;
    this->SolarSystemSpeed = 1.00f;
    this->SkyVisibility = 1.00f;
    this->ServerCorrectionTime = 1.00f;
    this->LockLocalBody = NULL;
    this->SkyLight = CreateDefaultSubobject<USkyLightComponent>(TEXT("Sky Light"));
    this->ServerTimeStamp = 0.00f;
    this->TargetSkyVisibility = 1.00f;
}

void ADayNight::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void ADayNight::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADayNight, ServerTimeStamp);
}


