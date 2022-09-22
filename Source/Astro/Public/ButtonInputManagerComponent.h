#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EButtonInput.h"
#include "ButtonInputManagerComponent.generated.h"

class UButtonComponent;
class UInputComponent;
class APlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UButtonInputManagerComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, UButtonComponent*> Buttons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* InputComponent;
    
public:
    UButtonInputManagerComponent();
    UFUNCTION(BlueprintCallable)
    void PushInputFocus(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void PopInputFocus(APlayerController* Controller);
    
private:
    UFUNCTION()
    void Confirm();
    
    UFUNCTION()
    void Cancel();
    
public:
    UFUNCTION(BlueprintCallable)
    void AddButton(UButtonComponent* Button, TEnumAsByte<EButtonInput> InputType);
    
};

