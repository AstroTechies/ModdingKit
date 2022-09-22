#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "RingCameraTargeter.generated.h"

class AActor;
class APlayController;
class USceneComponent;
class URingCameraTargeter;
class ASlotConnection;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API URingCameraTargeter : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidRadians;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* Center;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerCameraTargetLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> AvoidTargets;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference Slot;
    
public:
    URingCameraTargeter();
    UFUNCTION(BlueprintCallable)
    void SnapToTargetLocation(const FVector& TargetLocation);
    
    UFUNCTION(BlueprintCallable)
    void SnapToTarget(APlayController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(USceneComponent* TargetComponent, USceneComponent* RingCenter, FSlotReference TargetingSlot);
    
    UFUNCTION()
    void OnSlotDisconnected(FSlotReference ConnectedSlot, ASlotConnection* Connection);
    
    UFUNCTION()
    void OnSlotConnected(FSlotReference ConnectedSlot, ASlotConnection* Connection);
    
    UFUNCTION(BlueprintPure)
    static URingCameraTargeter* ActorRingCameraTargeter(AActor* Actor);
    
};

