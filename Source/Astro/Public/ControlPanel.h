#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "SignalDelegate.h"
#include "EControlPanelNavigationDirection.h"
#include "Components/SpotLightComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "ControlPanel.generated.h"

class APlayerController;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UCrackableActorComponent;
class UClickableComponent;
class UControlPanelCameraContext;
class UInputComponent;
class UPrimitiveComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AControlPanel : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOwnerChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RedirectOwnerInteractions: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USpotLightComponent* ControlPanelLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* CrackableActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ControlledActor, meta=(AllowPrivateAccess=true))
    AActor* ControlledActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UControlPanelCameraContext* CameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    uint8 bAutoOptimizeHierarchy: 1;
    
public:
    AControlPanel();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    bool OnSecondaryButtonPressedBP(APlayerController* Controller);
    
    UFUNCTION()
    void OnSecondaryButtonPressed();
    
    UFUNCTION()
    void OnRep_ControlledActor();
    
    UFUNCTION()
    void OnOwnerItemPickedUpOrUnslotted(bool bUnused);
    
    UFUNCTION()
    void OnNavigationComponentClicked(UPrimitiveComponent* navigationComponent, FKey ButtonPressed);
    
    UFUNCTION()
    void OnNavigateUpRepeat();
    
    UFUNCTION()
    void OnNavigateUpDown(float AxisValue);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateUpBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateUp();
    
    UFUNCTION()
    void OnNavigateRightRepeat();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateRightBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateRight();
    
    UFUNCTION()
    void OnNavigateLeftRight(float AxisValue);
    
    UFUNCTION()
    void OnNavigateLeftRepeat();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateLeftBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateLeft();
    
    UFUNCTION()
    void OnNavigateDownRepeat();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnNavigateDownBP(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnNavigateDown();
    
private:
    UFUNCTION()
    void OnCrackableActorComponentExaminableChanged();
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnControlledActorSet();
    
    UFUNCTION(BlueprintImplementableEvent)
    bool OnConfirmBP(APlayerController* Controller);
    
    UFUNCTION()
    void OnConfirm();
    
    UFUNCTION(BlueprintImplementableEvent)
    bool OnCancelBP(APlayerController* Controller);
    
    UFUNCTION()
    void OnCancel();
    
public:
    UFUNCTION(BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintPure)
    bool GetCracked() const;
    
    UFUNCTION()
    void FullyCrackedOrClosed(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked);
    
    UFUNCTION()
    void CrackedChanged(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked);
    
};

