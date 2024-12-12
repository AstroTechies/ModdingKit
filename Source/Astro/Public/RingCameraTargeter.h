#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "RingCameraTargeter.generated.h"

class AActor;
class APlayController;
class ASlotConnection;
class URingCameraTargeter;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API URingCameraTargeter : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidRadians;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Center;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerCameraTargetLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> AvoidTargets;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference Slot;
    
public:
    URingCameraTargeter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SnapToTargetLocation(const FVector& TargetLocation);
    
    UFUNCTION(BlueprintCallable)
    void SnapToTarget(APlayController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(USceneComponent* TargetComponent, USceneComponent* RingCenter, FSlotReference TargetingSlot);
    
    UFUNCTION(BlueprintCallable)
    void OnSlotDisconnected(FSlotReference ConnectedSlot, ASlotConnection* Connection);
    
    UFUNCTION(BlueprintCallable)
    void OnSlotConnected(FSlotReference ConnectedSlot, ASlotConnection* Connection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static URingCameraTargeter* ActorRingCameraTargeter(AActor* Actor);
    
};

