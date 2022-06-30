#include "AstroAudioStatics.h"

class AActor;
class UObject;

void UAstroAudioStatics::SetSwitch(FName SwitchGroup, FName SwitchState, AActor* Actor) {
}

void UAstroAudioStatics::SetState(FName StateGroup, FName State) {
}

void UAstroAudioStatics::SetRTPCValue(FName RTPC, float Value, int32 InterpolationTimeMs, AActor* Actor) {
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

UAstroAudioStatics::UAstroAudioStatics() {
}

