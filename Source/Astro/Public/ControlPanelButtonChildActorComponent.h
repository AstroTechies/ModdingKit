#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CustomChildActorComponent.h"
#include "SignalDelegate.h"
#include "EnableSignalDelegate.h"
#include "ControlPanelButtonChildActorComponent.generated.h"

class AControlPanelButton;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlPanelButtonChildActorComponent : public UCustomChildActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnButtonPressed;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnButtonArmedChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AControlPanelButton> ChildButtonClass;

protected:
    UPROPERTY()
    AControlPanelButton *ButtonActor;

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
