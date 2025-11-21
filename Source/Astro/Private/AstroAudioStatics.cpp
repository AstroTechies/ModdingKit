#include "AstroAudioStatics.h"

UAstroAudioStatics::UAstroAudioStatics() {
}

void UAstroAudioStatics::SetSwitch(FName SwitchGroup, FName SwitchState, AActor* Actor) {
}

void UAstroAudioStatics::SetState(FName StateGroup, FName State) {
}

void UAstroAudioStatics::SetRTPCValue(FName RTPC, float Value, int32 InterpolationTimeMs, AActor* Actor) {
}

void UAstroAudioStatics::RemoveSecondaryOutput(const int64 in_DeviceID) {
}

int32 UAstroAudioStatics::PostEventAttached(const FString& EventName, AActor* Actor, FName AttachPointName, bool bStopWhenAttachedToDestroyed) {
    return 0;
}

int32 UAstroAudioStatics::PostEventAtLocation(const FString& EventName, FVector Location, FRotator Orientation, UObject* WorldContextObject) {
    return 0;
}

int32 UAstroAudioStatics::PostEvent(const FString& EventName, AActor* Actor, bool bStopWhenAttachedToDestroyed) {
    return 0;
}

void UAstroAudioStatics::AddSecondaryOutput(const FString& in_AudioDeviceSharesetName, const int32 in_IdDevice, const uint8 in_PanRule, const uint8 in_ChannelConfig, int64& out_DeviceID) {
}


