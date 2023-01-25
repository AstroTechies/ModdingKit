#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ViewTargetTransitionParams -FallbackName=ViewTargetTransitionParams
#include "CameraMode.h"
#include "Templates/SubclassOf.h"
#include "CustomCameraRigComponent.generated.h"

class AActor;
class ACameraRigActor;
class UCameraContext;
class UCustomCameraRigComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraContext* ContextInstance;
    
public:
    UCustomCameraRigComponent();
    UFUNCTION(BlueprintCallable)
    void SetMode(FName Mode, const FViewTargetTransitionParams& params);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetModeName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACameraRigActor* GetCameraRigForMode(const FName Mode) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UCustomCameraRigComponent* ActorCustomCameraRig(AActor* Actor);
    
};

