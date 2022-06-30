#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SignalDelegate.h"
#include "EControlPanelNavigationDirection.h"
#include "InputCoreTypes.h"
#include "ControlPanel.generated.h"

class UControlPanelCameraContext;
class UInputComponent;
class USpotLightComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UCrackableActorComponent;
class UClickableComponent;
class APlayerController;
class UPrimitiveComponent;

UCLASS(Blueprintable, Abstract)
class ASTRO_API AControlPanel : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnOwnerChanged;

    UPROPERTY(EditDefaultsOnly)
    uint8 RedirectOwnerInteractions : 1;

protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    USkeletalMeshComponent *SkeletalMesh;

    UPROPERTY(Export, VisibleAnywhere)
    UStaticMeshComponent *StaticMesh;

    UPROPERTY(Export, VisibleAnywhere)
    USpotLightComponent *ControlPanelLight;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UCrackableActorComponent *CrackableActorComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UClickableComponent *ClickableComponent;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_ControlledActor, meta = (AllowPrivateAccess = true))
    AActor *ControlledActor;

    UPROPERTY(Export, Transient)
    UControlPanelCameraContext *CameraContext;

    UPROPERTY(Export)
    UInputComponent *FallbackInputComponent;

    UPROPERTY(EditDefaultsOnly)
    TMap<FName, EControlPanelNavigationDirection> NavigationComponentMap;

    UPROPERTY(EditDefaultsOnly)
    float FirstNavigationRepeatDelay;

    UPROPERTY(EditDefaultsOnly)
    float NavigationRepetitionInterval;

    UPROPERTY(EditDefaultsOnly)
    float AnalogStickNavigationThreshold;

    UPROPERTY(EditDefaultsOnly)
    uint8 bAutoOptimizeHierarchy : 1;

public:
    AControlPanel();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintImplementableEvent)
    bool OnSecondaryButtonPressedBP(APlayerController *Controller);

    UFUNCTION()
    void OnSecondaryButtonPressed();

    UFUNCTION()
    void OnRep_ControlledActor();

    UFUNCTION()
    void OnOwnerItemPickedUpOrUnslotted(bool bUnused);

    UFUNCTION()
    void OnNavigationComponentClicked(UPrimitiveComponent *navigationComponent, FKey ButtonPressed);

    UFUNCTION()
    void OnNavigateUpRepeat();

    UFUNCTION()
    void OnNavigateUpDown(float AxisValue);

    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateUpBP(APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
    void OnNavigateUp();

    UFUNCTION()
    void OnNavigateRightRepeat();

    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateRightBP(APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
    void OnNavigateRight();

    UFUNCTION()
    void OnNavigateLeftRight(float AxisValue);

    UFUNCTION()
    void OnNavigateLeftRepeat();

    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateLeftBP(APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
    void OnNavigateLeft();

    UFUNCTION()
    void OnNavigateDownRepeat();

    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateDownBP(APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
    void OnNavigateDown();

private:
    UFUNCTION()
    void OnCrackableActorComponentExaminableChanged();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnControlledActorSet();

    UFUNCTION(BlueprintImplementableEvent)
    bool OnConfirmBP(APlayerController *Controller);

    UFUNCTION()
    void OnConfirm();

    UFUNCTION(BlueprintImplementableEvent)
    bool OnCancelBP(APlayerController *Controller);

    UFUNCTION()
    void OnCancel();

public:
    UFUNCTION(BlueprintPure)
    bool IsLocallyControlled() const;

    UFUNCTION(BlueprintPure)
    bool GetCracked() const;

    UFUNCTION()
    void FullyCrackedOrClosed(UCrackableActorComponent *NewCrackableActorComponent, bool bIsCracked);

    UFUNCTION()
    void CrackedChanged(UCrackableActorComponent *NewCrackableActorComponent, bool bIsCracked);
};
