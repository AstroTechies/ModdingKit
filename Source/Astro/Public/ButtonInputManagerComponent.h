#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EButtonInput.h"
#include "ButtonInputManagerComponent.generated.h"

class APlayerController;
class UButtonComponent;
class UInputComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UButtonInputManagerComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, UButtonComponent*> Buttons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* InputComponent;
    
public:
    UButtonInputManagerComponent();
    UFUNCTION(BlueprintCallable)
    void PushInputFocus(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void PopInputFocus(APlayerController* Controller);
    
private:
    UFUNCTION(BlueprintCallable)
    void Confirm();
    
    UFUNCTION(BlueprintCallable)
    void Cancel();
    
public:
    UFUNCTION(BlueprintCallable)
    void AddButton(UButtonComponent* Button, TEnumAsByte<EButtonInput> InputType);
    
};

