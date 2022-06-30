#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "OnCrackedStateChangedDelegate.h"
#include "UObject/NoExportTypes.h"
#include "ECrackableActorNetworkingPolicy.h"
#include "Engine/EngineTypes.h"
#include "ECrackableActorMethod.h"
#include "CrackedReplicationData.h"
#include "UObject/NoExportTypes.h"
#include "CrackableActorComponent.generated.h"

class UCrackableActorComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCrackableActorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, Transient)
    FOnCrackedStateChanged OnCrackedChanged;

    UPROPERTY(BlueprintAssignable, Transient)
    FOnCrackedStateChanged OnFullyCrackedOrClosed;

    UPROPERTY(BlueprintAssignable, Transient)
    FSignal OnExaminableChanged;

protected:
    UPROPERTY(EditAnywhere)
    float CrackingSpeed;

    UPROPERTY(EditAnywhere)
    ECrackableActorMethod Method;

    UPROPERTY(EditAnywhere)
    FComponentReference CrackedOrientationComponent;

    UPROPERTY(EditAnywhere)
    FString OpenSoundEvent;

    UPROPERTY(EditAnywhere)
    FString CloseSoundEvent;

    UPROPERTY(EditAnywhere)
    ECrackableActorNetworkingPolicy NetworkingPolicy;

    UPROPERTY(EditAnywhere)
    uint8 bEncapsulateClicksWhenClosed : 1;

    UPROPERTY(EditAnywhere)
    uint8 bDisableComponentClicksWhenClosed : 1;

    UPROPERTY(ReplicatedUsing = OnRep_Cracked)
    FCrackedReplicationData ReplicationData;

    UPROPERTY()
    uint8 bCracked : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bClickToClose : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bCloseOnUnhandledClick : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bCloseWhenParentCrackableStateChanges : 1;

    UPROPERTY(EditAnywhere)
    uint8 bExaminable : 1;

    UPROPERTY(EditAnywhere)
    uint8 bCracksOnlyOnExamine : 1;

    UPROPERTY(EditAnywhere)
    float ClientScaleWhenCracked;

    UPROPERTY(EditAnywhere)
    float ScreenScaleRatio;

    UPROPERTY(EditAnywhere)
    FVector CameraSpaceOffset;

    UPROPERTY(EditAnywhere)
    float HoverHeight;

    UPROPERTY(EditAnywhere)
    float HideThreshold;

    UPROPERTY(EditAnywhere)
    float PivotAngle;

    UPROPERTY(ReplicatedUsing = OnRep_StartingRelativeTransform)
    FTransform StartingRelativeTransform;

public:
    UCrackableActorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateScreenScaleRatioAndCameraSpaceOffset(float ratio, FVector Offset);

public:
    UFUNCTION(BlueprintCallable)
    void SetCracked(bool cracked);

    UFUNCTION(BlueprintCallable)
    void SetClosedRelativeTransform(const FTransform &ClosedRelativeTransform);

protected:
    UFUNCTION()
    void OnRep_StartingRelativeTransform();

public:
    UFUNCTION()
    void OnRep_Cracked();

    UFUNCTION()
    void OnParentCrackedChanged(UCrackableActorComponent *parentCrackableActorComponent, bool bParentCracked);

    UFUNCTION()
    void OnClickUnhandled();

    UFUNCTION(BlueprintPure)
    bool IsExaminable() const;

    UFUNCTION(BlueprintPure)
    bool GetFullyOpen() const;

    UFUNCTION(BlueprintPure)
    bool GetFullyClosed() const;

    UFUNCTION(BlueprintPure)
    bool GetCracked() const;

    UFUNCTION(BlueprintPure)
    FTransform GetClosedRelativeTransform() const;

    UFUNCTION(BlueprintPure)
    bool CracksOnlyOnExamine() const;

    UFUNCTION(BlueprintPure)
    bool CanClickToClose() const;
};
