#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "CameraMode.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ViewTargetTransitionParams -FallbackName=ViewTargetTransitionParams
#include "CustomCameraRigComponent.generated.h"

class AActor;
class UCustomCameraRigComponent;
class UCameraContext;
class ACameraRigActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCustomCameraRigComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCameraMode> CameraModes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraContext> BehaviorContextClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACameraRigActor* ActiveRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UCameraContext* ContextInstance;
    
public:
    UCustomCameraRigComponent();
    UFUNCTION(BlueprintCallable)
    void SetMode(FName Mode, const FViewTargetTransitionParams& params);
    
    UFUNCTION(BlueprintPure)
    FName GetModeName() const;
    
    UFUNCTION(BlueprintPure)
    ACameraRigActor* GetCameraRigForMode(const FName Mode) const;
    
    UFUNCTION(BlueprintPure)
    static UCustomCameraRigComponent* ActorCustomCameraRig(AActor* Actor);
    
};

