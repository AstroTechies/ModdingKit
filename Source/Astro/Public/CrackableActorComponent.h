#pragma once
#include "CoreMinimal.h"
#include "CrackedReplicationData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OnCrackedStateChangedDelegate.h"
#include "ECrackableActorMethod.h"
#include "ECrackableActorNetworkingPolicy.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "CrackableActorComponent.generated.h"

class UCrackableActorComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCrackableActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnCrackedStateChanged OnCrackedChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnCrackedStateChanged OnFullyCrackedOrClosed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnExaminableChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrackingSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECrackableActorMethod Method;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference CrackedOrientationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OpenSoundEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CloseSoundEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECrackableActorNetworkingPolicy NetworkingPolicy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEncapsulateClicksWhenClosed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableComponentClicksWhenClosed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Cracked, meta=(AllowPrivateAccess=true))
    FCrackedReplicationData ReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCracked: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bClickToClose: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCloseOnUnhandledClick: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCloseWhenParentCrackableStateChanges: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bExaminable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCracksOnlyOnExamine: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClientScaleWhenCracked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScreenScaleRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CameraSpaceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HideThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PivotAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_StartingRelativeTransform, meta=(AllowPrivateAccess=true))
    FTransform StartingRelativeTransform;
    
public:
    UCrackableActorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateScreenScaleRatioAndCameraSpaceOffset(float ratio, FVector Offset);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCracked(bool cracked);
    
    UFUNCTION(BlueprintCallable)
    void SetClosedRelativeTransform(const FTransform& ClosedRelativeTransform);
    
protected:
    UFUNCTION()
    void OnRep_StartingRelativeTransform();
    
public:
    UFUNCTION()
    void OnRep_Cracked();
    
    UFUNCTION()
    void OnParentCrackedChanged(UCrackableActorComponent* parentCrackableActorComponent, bool bParentCracked);
    
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

