#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroAudioStatics.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class ASTRO_API UAstroAudioStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroAudioStatics();

    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void SetSwitch(FName SwitchGroup, FName SwitchState, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void SetState(FName StateGroup, FName State);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void SetRTPCValue(FName RTPC, float Value, int32 InterpolationTimeMs, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void RemoveSecondaryOutput(const int64 in_DeviceID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostEventAttached(const FString& EventName, AActor* Actor, FName AttachPointName, bool bStopWhenAttachedToDestroyed);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 PostEventAtLocation(const FString& EventName, FVector Location, FRotator Orientation, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostEvent(const FString& EventName, AActor* Actor, bool bStopWhenAttachedToDestroyed);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void AddSecondaryOutput(const FString& in_AudioDeviceSharesetName, const int32 in_IdDevice, const uint8 in_PanRule, const uint8 in_ChannelConfig, int64& out_DeviceID);
    
};

