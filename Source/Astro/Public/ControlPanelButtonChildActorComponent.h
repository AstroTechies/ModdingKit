#pragma once
#include "CoreMinimal.h"
#include "CustomChildActorComponent.h"
#include "EnableSignalDelegate.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
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
    UControlPanelButtonChildActorComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SpoofButtonPress();
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enabled);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RerouteOnPressed();
    
    UFUNCTION(BlueprintCallable)
    void RerouteOnArmedChanged(bool IsArmed);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetArmed();
    
};

