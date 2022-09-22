#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
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
    static int32 PostEventAttached(const FString& EventName, AActor* Actor, FName AttachPointName, bool bStopWhenAttachedToDestroyed);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostEventAtLocation(const FString& EventName, FVector Location, FRotator Orientation, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostEvent(const FString& EventName, AActor* Actor, bool bStopWhenAttachedToDestroyed);
    
};

