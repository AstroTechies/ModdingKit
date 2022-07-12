#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CustomChildActorComponent.h"
#include "SignalDelegate.h"
#include "EnableSignalDelegate.h"
#include "ControlPanelButtonChildActorComponent.generated.h"

class AControlPanelButton;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UControlPanelButtonChildActorComponent : public UCustomChildActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnButtonPressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnButtonArmedChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AControlPanelButton> ChildButtonClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AControlPanelButton* ButtonActor;
    
public:
    UControlPanelButtonChildActorComponent();
    UFUNCTION(BlueprintCallable)
    void SpoofButtonPress();
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enabled);
    
protected:
    UFUNCTION()
    void RerouteOnPressed();
    
    UFUNCTION()
    void RerouteOnArmedChanged(bool IsArmed);
    
public:
    UFUNCTION(BlueprintPure)
    bool GetEnabled();
    
    UFUNCTION(BlueprintPure)
    bool GetArmed();
    
};

