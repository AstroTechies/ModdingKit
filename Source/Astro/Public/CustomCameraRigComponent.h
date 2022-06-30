#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "CameraMode.h"
#include "Camera/PlayerCameraManager.h"
#include "CustomCameraRigComponent.generated.h"

class AActor;
class UCameraContext;
class ACameraRigActor;
class UCustomCameraRigComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UCustomCameraRigComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FCameraMode> CameraModes;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UCameraContext> BehaviorContextClass;

private:
    UPROPERTY()
    ACameraRigActor *ActiveRig;

    UPROPERTY(Export, Transient)
    UCameraContext *ContextInstance;

public:
    UCustomCameraRigComponent();
    UFUNCTION(BlueprintCallable)
    void SetMode(FName Mode, const FViewTargetTransitionParams &params);

    UFUNCTION(BlueprintPure)
    FName GetModeName() const;

    UFUNCTION(BlueprintPure)
    ACameraRigActor *GetCameraRigForMode(const FName Mode) const;

    UFUNCTION(BlueprintPure)
    static UCustomCameraRigComponent *ActorCustomCameraRig(AActor *Actor);
};
