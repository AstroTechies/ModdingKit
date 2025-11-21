#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
#include "EControlPanelNavigationDirection.h"
#include "ELogisticsComplexChannel.h"
#include "SignalDelegate.h"
#include "ControlPanel.generated.h"

class APlayerController;
class UClickableComponent;
class UControlPanelCameraContext;
class UCrackableActorComponent;
class UInputComponent;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USpotLightComponent;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AControlPanel : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOwnerChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RedirectOwnerInteractions: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpotLightComponent* ControlPanelLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* CrackableActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ControlledActor, meta=(AllowPrivateAccess=true))
    AActor* ControlledActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UControlPanelCameraContext* CameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputComponent* FallbackInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, EControlPanelNavigationDirection> NavigationComponentMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirstNavigationRepeatDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavigationRepetitionInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnalogStickNavigationThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELogisticsComplexChannel PadChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoOptimizeHierarchy: 1;
    
public:
    AControlPanel(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnSecondaryButtonPressedBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnSecondaryButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ControlledActor();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerItemPickedUpOrUnslotted(bool bUnused);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigationComponentClicked(UPrimitiveComponent* navigationComponent, FKey ButtonPressed);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateUpRepeat();
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateUpDown(float AxisValue);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNavigateUpBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateUp();
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateRightRepeat();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNavigateRightBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateRight();
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateLeftRight(float AxisValue);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateLeftRepeat();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNavigateLeftBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateLeft();
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateDownRepeat();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNavigateDownBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateDown();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCrackableActorComponentExaminableChanged();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnControlledActorSet();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnConfirmBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnConfirm();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnCancelBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnCancel();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCracked() const;
    
    UFUNCTION(BlueprintCallable)
    void FullyCrackedOrClosed(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked);
    
    UFUNCTION(BlueprintCallable)
    void CrackedChanged(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked);
    
};

